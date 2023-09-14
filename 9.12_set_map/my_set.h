#pragma once

#include "RB_tree.h"

namespace shr
{
	template<typename Key>
	class set
	{
	private:
		struct SetKeyOfT
		{
			const Key& operator()(const Key& key)
			{
				return key;
			}
		};

	public:
		typedef typename shr::RB_tree<Key, Key, SetKeyOfT>::const_iterator iterator;
		typedef typename shr::RB_tree<Key, Key, SetKeyOfT>::const_iterator const_iterator;

	public:
		iterator begin() const
		{
			return _tree.begin();
		}

		iterator end() const
		{
			return _tree.end();
		}

		std::pair<iterator, bool> insert(const Key& k)
		{
			std::pair<typename RB_tree<Key, Key, SetKeyOfT>::iterator, bool> p = _tree.insert(k);
			//用普通迭代器构造const迭代器
			return std::pair<iterator, bool>(p.first, p.second);
		}

	private:
		shr::RB_tree<Key, Key, SetKeyOfT> _tree;
	};
}