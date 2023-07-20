#pragma once

template<typename iterator, typename T, typename Ptr>
class reverse_iterator
{
public:
	typedef reverse_iterator<typename iterator, typename Ref, typename Ptr> self;

public:
	reverse_iterator(iterator it)
		:current(it)
	{ }

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