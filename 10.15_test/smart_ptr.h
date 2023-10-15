#pragma once

#include <iostream>
#include <functional>

using namespace std;

namespace shr
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{ }

		auto_ptr(const auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			_ptr = ap._ptr;
			ap._ptr = nullptr;
			return *this;
		}

		T& operator*() const
		{
			return *_ptr;
		}

		T* operator->() const
		{
			return _ptr;
		}

		T* get() const
		{
			return _ptr;
		}

		~auto_ptr()
		{
			delete _ptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr, function<void(T*)> del = [](T* ptr) { delete ptr; })
			:_ptr(ptr),
			_del(del)
		{ }

		unique_ptr(const unique_ptr<T>&) = delete;
		
		T& operator=(const unique_ptr<T>&) = delete;

		T& operator*() const
		{
			return *_ptr;
		}

		T* operator->() const
		{
			return _ptr;
		}

		T* get() const
		{
			return _ptr;
		}

		~unique_ptr()
		{
			_del(_ptr);
		}

	private:
		T* _ptr;
		function<void(T*)> _del;
	};

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr, function<void(T*)> del = [](T* p) { delete p; })
			:_ptr(ptr),
			_del(del),
			_pcount(new int(1))
		{ }

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr),
			_pcount(sp._pcount),
			_del(sp._del)
		{
			++(*_pcount);
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (sp._ptr != _ptr)
			{
				this->~shared_ptr();
				//_del(_ptr);
				//delete _pcount;
				_ptr = sp._ptr;
				_del = sp._del;
				_pcount = sp._pcount;
				++(*_pcount);
			}
			return *this;
		}

		T& operator*() const
		{
			return *_ptr;
		}

		T* operator->() const
		{
			return _ptr;
		}

		T* get() const
		{
			return _ptr;
		}

		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				_del(_ptr);
				delete _pcount;
				cout << "~shared_ptr()" << endl;
			}
		}

	private:
		T* _ptr;
		function<void(T*)> _del;
		int* _pcount;
	};

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{ }

		weak_ptr(const shr::shared_ptr<T>& sp)
			:_ptr(sp.get())
		{ }
		
		weak_ptr(const shr::weak_ptr<T>& wp)
			:_ptr(wp._ptr)
		{ }

		weak_ptr<T>& operator=(const shr::shared_ptr<T>& sp)
		{
			_ptr = sp.get();
			return *this;
		}

		weak_ptr<T>& operator=(const shr::weak_ptr<T>& wp)
		{
			_ptr = wp._ptr;
			return *this;
		}

		T& operator*() const
		{
			return *_ptr;
		}

		T* operator->() const
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}