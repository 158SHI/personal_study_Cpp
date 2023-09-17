#pragma once

#include <utility>
#include <vector>
#include <string>

using namespace std;

namespace shr
{
	//����̽������ϣ��ͻ
	namespace LinearProbing
	{

	}

	//��ϣͰ�ṹ
	namespace HashBucket
	{
		template<class Key>
		struct HashFuncDefault
		{
			//��������������͡�������
			size_t operator()(const Key& key)
			{
				return (size_t)key;
			}
		};

		template<>
		struct HashFuncDefault<std::string>
		{
			//����ַ�������
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
				//����������Ϊ 1 ʱ���������Ա�֤����Ч��
				if (_size == _table.size())
				{
					//����
					size_t newSize = _table.size() * 2;
					vector<Node*> newTable;
					newTable.resize(newSize);
					//���ɽڵ������±�
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
				//�ҵ�����λ��
				size_t hashi = hf(kv.first) % _table.size();
				//���½ڵ�ͷ�����ϣͰ��
				Node* newNode = new Node(kv);
				newNode->_next = _table[hashi];
				_table[hashi] = newNode;
				++_size; //������Ч���ݸ���
				
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
			size_t _size; //��Ч���ݸ���
		};
	}
}