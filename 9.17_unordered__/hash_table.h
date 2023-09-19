#pragma once

#include <utility>
#include <vector>
#include <string>

using namespace std;

namespace shr
{
	//线性探测解决哈希冲突
	namespace LinearProbing
	{ }

	//哈希桶结构
	namespace HashBucket
	{
		template<class Key>
		struct HashFuncDefault
		{
			//可以针对正负整型、浮点型
			size_t operator()(const Key& key)
			{
				return (size_t)key;
			}
		};

		template<>
		struct HashFuncDefault<std::string>
		{
			//针对字符串类型
			size_t operator()(const string& str)
			{
				size_t hash = 0;
				for (auto& ch : str) {
					hash = hash * 113 + ch;
				}
				return hash;
			}
		};

		template<class T>
		struct HashNode;

		template<class Key, class T, class KeyOfT, class HashFunc = HashFuncDefault<Key>>
		class hash_table;

		template<class Key, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
		struct __hash_table_iterator
		{
		private:
			typedef HashNode<T> Node;
			typedef __hash_table_iterator<Key, T, T&, T*, KeyOfT, HashFunc> iterator;
			typedef __hash_table_iterator<Key, T, Ref, Ptr, KeyOfT, HashFunc> Self;
			typedef shr::HashBucket::hash_table<Key, T, KeyOfT, HashFunc> HashTable;

		public:
			Node* _node;
			const HashTable* _hash_table;

			__hash_table_iterator(Node* node, const HashTable* hash_table)
				:_node(node), 
				_hash_table(hash_table)
			{ }

			//对于iterator，这个函数是拷贝构造
			//对于const_iterator，这个函数是构造
			//使用iterator构造const_iterator
			__hash_table_iterator(const iterator& it)
				:_node(it._node),
				_hash_table(it._hash_table)
			{ }

			Ref operator*()
			{
				return _node->_data;
			}

			Ptr operator->()
			{
				return &(_node->_data);
			}

			Self& operator++()
			{
				KeyOfT kot;
				HashFunc hf;
				if (_node->_next) {
					_node = _node->_next;
				}
				else
				{
					//寻找下一个不为空的哈希桶
					int hashi = hf(kot(_node->_data)) % _hash_table->_table.size();
					for (int i = hashi + 1; i < _hash_table->_table.size(); ++i)
					{
						if ((_hash_table->_table)[i])
						{
							_node = (_hash_table->_table)[i];
							return *this;
						}
					}
					_node = nullptr;
				}
				return *this;
			}

			Self operator++(int)
			{
				Self tmpIt = *this;
				operator++();
				return tmpIt;
			}

			bool operator==(const Self& it)
			{
				return _node == it._node;
			}

			bool operator!=(const Self& it)
			{
				return _node != it._node;
			}
		};

		template<class T>
		struct HashNode
		{
		private:
			typedef HashNode<T> Node;

		public:
			T _data;
			Node* _next;

			HashNode(const T& data)
				:_data(data),
				_next(nullptr)
			{ }
		};

		template<class Key, class T, class KeyOfT, class HashFunc>
		class hash_table
		{
			template<class Key, class T, class Ref, class Ptr, class KeyOfT, class HashFunc>
			friend struct __hash_table_iterator;
		
		public:
			typedef __hash_table_iterator<Key, T, T&, T*, KeyOfT, HashFunc> iterator;
			typedef __hash_table_iterator<Key, T, const T&, const T*, KeyOfT, HashFunc> const_iterator;

		private:
			typedef HashNode<T> Node;

		public:
			hash_table()
				:_size(0)
			{
				_table.resize(10);
			}

			iterator begin()
			{
				//找到第一个不为空的哈希桶的头结点
				for (int i = 0; i < _size; ++i)
				{
					if (_table[i]) {
						return iterator(_table[i], this);
					}
				}
				return iterator(nullptr, this);
			}

			iterator end()
			{
				return iterator(nullptr, this);
			}

			const_iterator begin() const
			{
				//找到第一个不为空的哈希桶的头结点
				for (int i = 0; i < _size; ++i)
				{
					if (_table[i]) {
						return iterator(_table[i], this);
					}
				}
				return const_iterator(nullptr, this);
			}

			const_iterator end() const
			{
				return const_iterator(nullptr, this);
			}

			iterator find(const Key& key) const
			{
				HashFunc hf;
				KeyOfT kot;
				int hashi = hf(key) % _table.size(); //找到目标节点的索引
				Node* cur = _table[hashi];
				//遍历哈希桶
				while (cur)
				{
					if (kot(cur->_data) == key) {
						return iterator(cur, this);
					}
					cur = cur->_next;
				}
				return iterator(nullptr, this);
			}

			pair<iterator, bool> insert(const T& data)
			{
				HashFunc hf;
				KeyOfT kot;

				iterator retFind = find(kot(data));
				if (retFind != end()) {
					return make_pair(retFind, false);
				}

				//当负载因子为 1 时进行扩容以保证查找效率
				if (_size == _table.size())
				{
					//扩容
					size_t newSize = _table.size() * 2;
					vector<Node*> newTable;
					newTable.resize(newSize);
					//将旧节点链入新表
					for (int i = 0; i < _table.size(); ++i)
					{
						Node* cur = _table[i];
						while (cur)
						{
							Node* nextNode = cur->_next;
							int hashi = hf(kot(cur->_data)) % newSize;
							cur->_next = newTable[hashi];
							newTable[hashi] = cur;
							cur = nextNode;
						}
					}
					_table.swap(newTable);
				}

				//找到索引位置
				size_t hashi = hf(kot(data)) % _table.size();
				//将新节点头插入哈希桶中
				Node* newNode = new Node(data);
				newNode->_next = _table[hashi];
				_table[hashi] = newNode;
				++_size; //更新有效数据个数
				
				return make_pair(iterator(newNode, this), true);
			}

			iterator erase(const Key& key)
			{
				HashFunc hf;
				KeyOfT kot;
				int hashi = hf(kot(key)) % _table.size(); //找到欲删除结点的索引
				Node* cur = _table[hashi];
				Node* preNode = nullptr;
				//遍历哈希桶找到目标值
				while (cur)
				{
					if (kot(cur->_data) == key)
					{
						Node* nextNode = cur->_next;
						//删除哈希桶的头结点
						if (preNode == nullptr) {
							_table[hashi] = nextNode;
						}
						else {
							preNode->_next = nextNode;
						}
						iterator retIt = ++iterator(cur, this);
						delete cur;
						--_size;
						return retIt;
					}
					preNode = cur;
					cur = cur->_next;
				}
				return iterator(nullptr, this);
			}

			~hash_table()
			{
				//逐个释放哈希桶
				for (int i = 0; i < _table.size(); ++i)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* nextNode = cur->_next;
						delete cur;
						cur = nextNode;
					}
					_table[i] = nullptr;
				}
			}
			
		private:
			vector<Node*> _table;
			size_t _size; //有效数据个数
		};
	}
}