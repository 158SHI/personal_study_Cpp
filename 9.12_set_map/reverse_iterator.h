#pragma once

namespace shr
{
	template<typename iterator, typename Ref, typename Ptr>
	class reverse_iterator
	{
	private:
		typedef reverse_iterator<iterator, Ref, Ptr> self;

	public:
		reverse_iterator(iterator it)
			:_current(it)
		{ }

		self& operator++()
		{
			--_current;
			return *this;
		}

		self operator++(int)
		{
			return _current--;
		}

		self& operator--()
		{
			++_current;
			return *this;
		}

		self operator--(int)
		{
			return _current++;
		}

		Ref operator*()
		{
			iterator tmp = _current;
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		bool operator==(const self& it)
		{
			return _current == it._current;
		}

		bool operator!=(const self& it)
		{
			return _current != it._current;
		}

	private:
		iterator _current;
	};
}
