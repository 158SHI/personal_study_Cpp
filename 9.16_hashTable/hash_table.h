#pragma once

#include <utility>
#include <vector>
#include <string>

using namespace std;

namespace shr
{
	//线性探测解决哈希冲突
	namespace LinearProbing
	{

	}

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

		template<class Key, class Value>
		struct HashNode
		{
		private:
			typedef HashNode<Key, Value> Node;

		public:
			pair<Key, Value> _kv;
			Node* _next;

			HashNode(const pair<Key, Value>& kv)
				:_kv(kv), 
				_next(nullptr)
			{ }
		};

		template<class Key, class Value, class HashFunc = HashFuncDefault<Key>>
		class hash_table
		{
		private:
			typedef HashNode<Key, Value> Node;

		public:
			hash_table()
			{
				_table.resize(10);
				_size = 0;
			}

			pair<Key, Value>* find(const Key& key)
			{
				HashFunc hf;
				int hashi = hf(key) % _table.size();
				Node* cur = _table[hashi];
				while (cur)
				{
					if (cur->_kv.first == key) {
						return &(cur->_kv);
					}
					cur = cur->_next;
				}
				return nullptr;
			}

			bool insert(const pair<Key, Value>& kv)
			{
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
							int hashi = cur->_kv.first % newSize;
							cur->_next = newTable[hashi];
							newTable[hashi] = cur;
							cur = nextNode;
						}
					}
					_table.swap(newTable);
				}

				HashFunc hf;
				//找到索引位置
				size_t hashi = hf(kv.first) % _table.size();
				//将新节点头插入哈希桶中
				Node* newNode = new Node(kv);
				newNode->_next = _table[hashi];
				_table[hashi] = newNode;
				++_size; //更新有效数据个数
				
				return true;
			}

			bool erase(const Key& key)
			{
				HashFunc hf;
				int hashi = hf(key) % _table.size();
				Node* cur = _table[hashi];
				Node* preNode = nullptr;
				while (cur)
				{
					if (cur->_kv.first == key)
					{
						Node* nextNode = cur->_next;
						if (preNode == nullptr) {
							_table[hashi] = nextNode;
						}
						else {
							preNode->_next = nextNode;
						}
						delete cur;
						--_size;
						return true;
					}
					preNode = cur;
					cur = cur->_next;
				}
				return false;
			}

			~hash_table()
			{
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