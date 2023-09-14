#pragma once

#include "RB_tree.h"

namespace shr
{
	template<typename Key, typename Value>
	class map
	{
	private:
		struct MapKeyOfT
		{
			const Key& operator()(const std::pair<const Key, Value>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename RB_tree<Key, std::pair<const Key, Value>, MapKeyOfT>::iterator iterator;
		typedef typename RB_tree<Key, std::pair<const Key, Value>, MapKeyOfT>::const_iterator const_iterator;

	public:
		iterator begin()
		{
			return _tree.begin();
		}

		iterator end()
		{
			return _tree.end();
		}

		const_iterator begin() const
		{
			return _tree.begin();
		}

		const_iterator end() const
		{
			return _tree.end();
		}

		std::pair<iterator, bool> insert(const std::pair<Key, Value>& kv)
		{
			return _tree.insert(kv);
		}

		Value& operator[](const Key& key)
		{
			std::pair<iterator, bool> ret = _tree.insert(std::make_pair(key, Value()));
			return ret.first->second;
		}

	private:
		shr::RB_tree<Key, std::pair<const Key, Value>, MapKeyOfT> _tree;
	};
}