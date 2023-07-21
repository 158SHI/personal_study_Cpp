#pragma once

namespace shr
{
	template<typename iterator, typename Ref, typename Ptr>
	class reverse_iterator
	{
	private:
		typedef reverse_iterator<typename iterator, typename Ref, typename Ptr> Self;

	public:
		reverse_iterator(iterator it)
			:_current(it)
		{ }

		Ref operator*()
		{
			iterator tmp = _current;
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			--_current;
			return *this;
		}

		Self& operator--()
		{
			++_current;
			return *this;
		}

		Self& operator++(int)
		{
			Self tmp = _current;
			--_current;
			return tmp;
		}

		Self& operator--(int)
		{
			Self tmp = _current;
			++_current;
			return tmp;
		}

		bool operator==(Self rit)
		{
			return _current == rit._current;
		}

		bool operator!=(Self rit)
		{
			return _current != rit._current;
		}

	private:
		iterator _current;
	};
}