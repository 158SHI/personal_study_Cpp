#pragma once

#include <vector>
#include <algorithm>

namespace shr
{
	template<typename T>
	class less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<typename T>
	class greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<typename T, typename Container = std::vector<T>, typename compare = shr::less<T>>
	class priority_queue
	{
	private:
		void AdjustDown(int parent)
		{
			int child = parent * 2 + 1;
			int n = _con.size();
			while (child < n)
			{
				if (child + 1 < n && compare()(_con[child], _con[child + 1])) {
					++child;
				}

				if (compare()(_con[parent], _con[child]))
				{
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					break;
				}
			}
		}

		void AdjustUp(int node)
		{
			int child = node;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (compare()(_con[parent], _con[child]))
				{
					std::swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else {
					break;
				}
			}
		}

	public:
		template<typename InputIterator>
		priority_queue(InputIterator first, InputIterator end)
		{
			while (first != end)
			{
				_con.push_back(*first);
				++first;
			}

			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i) {
				AdjustDown(i);
			}
		}

		void push(const T& val)
		{
			_con.push_back(val);
			AdjustUp(_con.size() - 1);
		}

		void pop()
		{
			std::swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};
}