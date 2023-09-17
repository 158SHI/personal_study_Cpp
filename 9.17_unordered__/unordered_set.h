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

		bool insert(const Key& key)
		{
			return _hash_table.insert(key);
		}

		bool erase(const Key& key)
		{

		}

		Key* find(const Key& key)
		{
			return _hash_table.find(key);
		}

	private:
		HashBucket::hash_table<Key, Key, KeyOfTSet> _hash_table;
	};
}