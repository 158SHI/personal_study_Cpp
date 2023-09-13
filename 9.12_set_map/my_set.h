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
		iterator begin()
		{
			return _tree.cbegin();
		}

		const_iterator cbegin()
		{
			return _tree.cbegin();
		}

		iterator end()
		{
			return _tree.cend();
		}

		const_iterator cend()
		{
			return _tree.cend();
		}

		//无法解决返回值的问题
		//tree的插入返回的是一个iterator,而此处返回的是一个const_iterator
		//iterator insert(const Key& k)
		//{
		//	return _tree.insert(k);
		//}

	private:
		shr::RB_tree<Key, Key, SetKeyOfT> _tree;
	};
}