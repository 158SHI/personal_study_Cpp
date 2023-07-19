#pragma once

#include <vector>
#include <list>
#include <deque>

namespace shr
{
	template<typename T, typename Container = std::deque<T> >
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_back();
		}

		bool empty()
		{
			return _con.empty();
		}

		T& top()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

	private:
		Container _con;
	};
}