#pragma once

namespace shr
{
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr)
			:_ptr(ptr)
		{ }

		auto_ptr(const auto_ptr& ap)
		{
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}

		auto_ptr<T> operator=(const auto_ptr& ap)
		{
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}

		T* get() const
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		const T& operator*() const
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		const T* operator->() const
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
		unique_ptr(T* ptr)
			:_ptr(ptr)
		{ }

		unique_ptr(const unique_ptr& up) = delete;

		unique_ptr<T> operator=(const unique_ptr& up) = delete;

		T* get() const
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		const T& operator*() const
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		const T* operator->() const
		{
			return _ptr;
		}

		~unique_ptr()
		{
			delete _ptr;
		}

	private:
		T* _ptr;
	};

	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr), _pcount(new int(1))
		{ }

		shared_ptr(const shared_ptr& sp)
			:_ptr(sp._ptr), _pcount(sp._pcount)
		{
			*_pcount++;
		}

		shared_ptr<T> operator=(const shared_ptr& sp)
		{
			//1.自己跟自己赋值的情况
			//2.维护同一块空间的指针之间的赋值情况
			if (_ptr != sp._ptr)
			{
				if (--(*_pcount) == 0)
				{
					delete _ptr;
					delete _pcount;
				}
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				*_pcount++;
			}
			return *this;
		}

		T* get() const
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		const T& operator*() const
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		const T* operator->() const
		{
			return _ptr;
		}

		~shared_ptr()
		{
			if (--(*_pcount) == 0)
			{
				delete _ptr;
				delete _pcount;
			}
		}

	private:
		T* _ptr;
		int* _pcount;
	};

	//专门解决shared_ptr的循环引用问题
	//不属于RAII
	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
			:_ptr(nullptr)
		{ }

		weak_ptr(const weak_ptr& wp)
			:_ptr(wp._ptr)
		{ }

		template<class U>
		weak_ptr(const weak_ptr<U>& wp)
			:_ptr(wp._ptr)
		{ }

		template<class U>
		weak_ptr(const shr::shared_ptr<U>& wp)
			: _ptr(wp._ptr)
		{ }

		weak_ptr<T>& operator=(const shr::shared_ptr<T>& sp)
		{
			_ptr = sp.get();
			return *this;
		}

		weak_ptr<T>& operator=(const shr::weak_ptr<T>& sp)
		{
			_ptr = sp._ptr;
			return *this;
		}

		T* get() const
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}

		const T& operator*() const
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		const T* operator->() const
		{
			return _ptr;
		}

	private:
		T* _ptr;
	};
}