#pragma once

#include "hash_table.h"

namespace shr
{
	template<class Key>
	class unordered_set
	{
	public:
		struct KeyOfTSet
		{
			const Key& operator()(const Key& key)
			{
				return key;
			}
		};

	public:
		typedef typename shr::HashBucket::hash_table<Key, Key, KeyOfTSet>::iterator iterator;

		iterator begin()
		{
			return _hash_table.begin();
		}

		iterator end()
		{
			return _hash_table.end();
		}

		iterator insert(const Key& key)
		{
			return _hash_table.insert(key);
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
		HashBucket::hash_table<Key, Key, KeyOfTSet> _hash_table;
	};
}