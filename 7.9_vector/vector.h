#pragma once

#include <assert.h>
#include <string.h>
#include <algorithm>

namespace shr
{
	template<typename T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef T* const_iterator;

		vector()
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{ }

		vector(const vector<T>& v)
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storage(nullptr)
		{
			size_t capa = v.capacity();
			iterator tmp = new T[capa];
			//不能直接使用memcpy，否则会对自定义类型进行浅拷贝
			for (int i = 0; i < v.size(); ++i) {
				tmp[i] = v[i];
			}
			_start = tmp;
			_finish = tmp + v.size();
			_end_of_storage = tmp + capa;
		}

		vector(size_t n, const T& val = T())
		{
			resize(n, val);
		}

		//针对误调用迭代器构造函数的问题
		vector(int n, const T& val = T())
		{
			resize(n, val);
		}

		template<typename InputIterator>
		vector(InputIterator first, InputIterator end)
		{
			//[first, end)
			while (first != end)
			{
				push_back(*first);
				++first;
			}
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		iterator begin()
		{
			return _start;
		}

		const_iterator begin() const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator end() const
		{
			return _finish;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return *(_start + pos);
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				int old_size = size();
				iterator tmp = new T[n];
				if (_start)
				{
					//不能直接使用memcpy
					for (int i = 0; i < old_size; ++i) {
						tmp[i] = (*this)[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n <= size()) {
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		void push_back(const T& val)
		{
			//if (size() == capacity())
			//{
			//	size_t capacity = size() == 0 ? 4 : size() * 2;
			//	reserve(capacity);
			//}
			//*_finish = val;
			//++_finish;
			insert(_finish, val);
		}

		void pop_back()
		{
			assert(size() > 0);
			--_finish;
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start && pos <= _finish);
			if (size() == capacity())
			{
				size_t capacity = size() == 0 ? 4 : size() * 2;
				reserve(capacity);
				//扩容后迭代器可能失效，要在内部更新迭代器
				pos = _start + size();
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);
			assert(size() > 0);
			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
			return pos;
		}

		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}