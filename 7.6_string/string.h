#pragma once

#include <iostream>
#include <algorithm>
#include <assert.h>

namespace shr
{
	class string
	{
		friend ostream& operator<<(ostream& cout, const string& s)
		{
			cout << s.c_str();
			return cout;
		}

		friend istream& operator>>(istream& cin, string& s)
		{
			
		}

	private:
		size_t _size;
		size_t _capacity;
		char* _str;

	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		static const size_t npos;

	public:
		string(const char* str = "")
			:_size(strlen(str)), 
			_capacity(_size),
			_str(new char[_size + 1]) //+1是为了给'\0'预留空间
		{
			strcpy(_str, str);
		}

		string(const string& s)
		{
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str() const
		{
			return _str;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		size_t size() const
		{
			return _size;
		}

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		void reserve(size_t n)
		{
			char* tmp = new char[n + 1]; //为'\0'多开一个字节空间
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}

		void push_back(char ch)
		{
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : _size * 2); //push之前有可能是空串，_capacity为0,
			}
			_str[_size++] = ch;
			_str[_size] = '\0'; //末尾补'\0'
		}

		void append(const char* str)
		{
			int len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos, size_t n, char ch)
		{
			assert(pos < _size);
			if (_size + n > _capacity) {
				reserve(_size + n);
			}

			size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + n] = _str[end];
				--end;
			}

			for (int i = 0; i < n; ++i) {
				_str[pos + i] = ch;
			}
			_size += n; //注意不要忘记调整_size

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			int len = strlen(str);
			if (_size + len > _capacity) {
				reserve(_size + len);
			}

			size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			for (int i = 0; i < len; ++i) {
				_str[pos + i] = str[i];
			}

			_size += len;

			return *this;
		}

		void erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size) {
				_str[pos] = '\0';
			}
			else
			{
				size_t end = pos + len;
				while (end <= _size) {
					_str[pos++] = _str[end++];
				}
			}
			//注意不能直接_size -= len,len 可能是npos
			_size = pos;
		}

		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);
			for (int i = pos; i < _size; ++i)
			{
				if (_str[i] == ch) {
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			char* ret = strstr(_str, str);
			if (ret) {
				return ret - _str;
			}
			else {
				return npos;
			}
		}

		string substr(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			string tmp;
			if (len == npos || len + pos > _size)
			{
				for (int i = pos; i < _size; ++i) {
					tmp += _str[i];
				}
			}
			else
			{
				for (int i = pos; i < pos + len; ++i) {
					tmp += _str[i];
				}
			}
			return tmp;
		}

		void resize(size_t n, char ch = '\0')
		{
			if(n <= _size) {
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				reserve(n);
				size_t begin = _size;
				while (_size < n) {
					push_back(ch);
				}
			}
		}

		bool empty()
		{
			return _size == 0;
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		void clear()
		{
			erase();
		}

		bool operator>(const string& s)
		{
			return strcmp(this->c_str(), s.c_str()) > 0 ? true : false;
		}

		bool operator==(const string& s)
		{
			return strcmp(this->c_str(), s.c_str()) == 0 ? true : false;
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		bool operator<(const string& s)
		{
			return (!(*this > s) && !(*this == s));
		}

		bool operator>=(const string& s)
		{
			return (*this > s || *this == s);
		}

		bool operator<=(const string& s)
		{
			return (*this < s || *this == s);
		}
	};

	const size_t string::npos = -1;
}