#pragma once

#include "hash_table.h"

namespace shr
{
	template<class Key, class Value>
	class unordered_map
	{
	public:
		struct KeyOfTMap
		{
			const Key& operator()(const pair<Key, Value>& kv)
			{
				return kv.first;
			}
		};

		bool insert(const pair<Key, Value>& kv)
		{
			return _hash_table.insert(kv);
		}

		pair<Key, Value>* find(const Key& key)
		{
			return _hash_table.find(key);
		}

	private:
		HashBucket::hash_table<Key, pair<Key, Value>, KeyOfTMap> _hash_table;
	};
}
