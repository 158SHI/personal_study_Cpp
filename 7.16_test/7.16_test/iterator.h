#pragma once

namespace shr
{
	template<typename iterator, typename Ref, typename Ptr>
	class reverse_iterator
	{
	public:
		typedef reverse_iterator<typename iterator, typename Ref, typename Ptr> self;

	public:
		reverse_iterator(iterator it)
			:current(it)
		{ }

		self& operator++()
		{
			--current;
			return *this;
		}

		self& operator--()
		{
			++current;
			return *this;
		}

		self operator++(int)
		{
			self tmp = current;
			--current;
			return tmp;
		}

		self operator--(int)
		{
			self tmp = current;
			++current;
			return tmp;
		}

		bool operator==(const self& it)
		{
			return current == it.current;
		}

		bool operator!=(self it)
		{
			return current != it.current;
		}

		Ref operator*()
		{
			iterator tmp = current;
			return *(--tmp);
		}

		Ptr operator->()
		{
			return &(operator*());
		}

	private:
		iterator current;
	};
}