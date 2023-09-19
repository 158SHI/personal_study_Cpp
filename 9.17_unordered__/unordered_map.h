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
			const Key& operator()(const pair<const Key, Value>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename shr::HashBucket::hash_table<Key, pair<const Key, Value>, KeyOfTMap>::iterator iterator;
		typedef typename shr::HashBucket::hash_table<Key, pair<const Key, Value>, KeyOfTMap>::const_iterator const_iterator;

		iterator begin()
		{
			return _hash_table.begin();
		}

		iterator end()
		{
			return _hash_table.end();
		}

		const_iterator begin() const
		{
			return _hash_table.begin();
		}

		const_iterator end() const
		{
			return _hash_table.end();
		}

		pair<iterator, bool> insert(const pair<Key, Value>& kv)
		{
			pair<typename HashBucket::hash_table<Key, pair<const Key, Value>, KeyOfTMap>::iterator, bool> ret =
				_hash_table.insert(kv);
			return pair<iterator, bool>(ret.first, ret.second);
		}

		iterator erase(const Key& key)
		{
			return _hash_table.erase(key);
		}

		iterator find(const Key& key) const
		{
			return _hash_table.find(key);
		}

		Value& operator[](const Key& key)
		{
			//解决迭代器不兼容问题
			pair<iterator, bool> retInsert = insert(make_pair(key, Value()));
			return retInsert.first->second;
		}

		const Value& operator[](const Key& key) const
		{
			//解决迭代器不兼容问题
			pair<iterator, bool> retInsert = insert(make_pair(key, Value()));
			return retInsert.first->second;
		}

	private:
		HashBucket::hash_table<Key, pair<const Key, Value>, KeyOfTMap> _hash_table;
	};
}
