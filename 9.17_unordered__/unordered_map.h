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

	public:
		typedef typename shr::HashBucket::hash_table<Key, pair<Key, Value>, KeyOfTMap>::iterator iterator;

		iterator begin()
		{
			return _hash_table.begin();
		}

		iterator end()
		{
			return _hash_table.end();
		}

		iterator insert(const pair<Key, Value>& kv)
		{
			return _hash_table.insert(kv);
		}

		iterator erase(const Key& key)
		{
			return _hash_table.erase(key);
		}

		iterator find(const Key& key)
		{
			return _hash_table.find(key);
		}

	private:
		HashBucket::hash_table<Key, pair<Key, Value>, KeyOfTMap> _hash_table;
	};
}
