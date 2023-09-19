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
		typedef typename shr::HashBucket::hash_table<Key, Key, KeyOfTSet>::const_iterator iterator;
		typedef typename shr::HashBucket::hash_table<Key, Key, KeyOfTSet>::const_iterator const_iterator;

		iterator begin() const
		{
			return _hash_table.begin();
		}

		iterator end() const
		{
			return _hash_table.end();
		}

		pair<iterator, bool> insert(const Key& key)
		{
			return _hash_table.insert(key);
		}

		iterator erase(const Key& key)
		{
			return _hash_table.erase(key);
		}

		iterator find(const Key& key) const
		{
			typename HashBucket::hash_table<Key, Key, KeyOfTSet>::iterator ret = _hash_table.find(key);
			return iterator(ret);
		}

	private:
		HashBucket::hash_table<Key, Key, KeyOfTSet> _hash_table;
	};
}