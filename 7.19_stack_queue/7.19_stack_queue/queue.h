#pragma once

#include <vector>
#include <list>
#include <deque>

namespace shr
{
	template<typename T, typename Container = std::deque<T> >
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front();
		}

		bool empty()
		{
			return _con.empty();
		}

		T& front()
		{
			return _con.front();
		}
			
		T& back()
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