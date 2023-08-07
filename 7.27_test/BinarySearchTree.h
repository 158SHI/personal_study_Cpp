#pragma once

#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

namespace shr
{
	namespace key_model_tree
	{
		template<typename Key>
		struct BinarySearchTreeNode
		{
			typedef BinarySearchTreeNode<Key> BST_Node;

			BinarySearchTreeNode(const Key& val)
				:_left(nullptr),
				_right(nullptr),
				_val(val)
			{ };

			BST_Node* _left;
			BST_Node* _right;
			Key _val;
		};

		template<typename Key>
		class BinarySearchTree
		{
		private:
			typedef BinarySearchTreeNode<Key> BST_Node;
			typedef BinarySearchTree<Key> Self;

		public:
			BinarySearchTree()
				:_root(nullptr)
			{ }

			BinarySearchTree(const Self& BSTree)
			{
				_root = _copyConstruct(BSTree._root);
			}

			Self& operator=(Self BSTree)
			{
				std::swap(_root, BSTree._root);
				return *this;
			}

			const Self& operator=(Self BSTree) const
			{
				std::swap(_root, BSTree._root);
				return *this;
			}

			~BinarySearchTree()
			{
				Destroy(_root);
			}

			bool Insert(const Key& val)
			{
				if (!_root) {
					_root = new BST_Node(val);
					return true;
				}

				BST_Node* cur = _root;
				BST_Node* parent = nullptr;
				while (cur)
				{
					if (val < cur->_val) {
						parent = cur;
						cur = cur->_left;
					}
					else if (val > cur->_val) {
						parent = cur;
						cur = cur->_right;
					}
					else {
						return false;
					}
				}

				if (val < parent->_val) {
					parent->_left = new BST_Node(val);
				}
				else {
					parent->_right = new BST_Node(val);
				}
				return true;
			}

			bool Erase(const Key& val)
			{
				//没有子节点
				//有一个子节点
				//有两个子节点
				BST_Node* pos = _root;
				BST_Node* parent = nullptr;
				while (pos)
				{
					if (val < pos->_val) {
						parent = pos;
						pos = pos->_left;
					}
					else if (val > pos->_val) {
						parent = pos;
						pos = pos->_right;
					}
					else {
						break;
					}
				}
				if (pos)
				{
					//没有子节点 或 有一个子节点
					if (pos->_left == nullptr)
					{
						if (pos == _root) {
							_root = pos->_right;
						}
						else
						{
							if (pos == parent->_left) {
								parent->_left = pos->_right;
							}
							else {
								parent->_right = pos->_right;
							}
						}
						delete pos;
					}
					else if (pos->_right == nullptr)
					{
						if (pos == _root) {
							_root = pos->_left;
						}
						else
						{
							if (pos == parent->_left) {
								parent->_left = pos->_left;
							}
							else {
								parent->_right = pos->_left;
							}
						}
						delete pos;
					} //有两个子节点
					else
					{
						BST_Node* cur = pos->_left;
						BST_Node* parent = pos;
						//找左子树的最大key节点
						while (cur->_right)
						{
							parent = cur;
							cur = cur->_right;
						}
						std::swap(cur->_val, pos->_val);

						//删除cur节点
						if (cur->_left == nullptr)
						{
							if (cur == parent->_left) {
								parent->_left = cur->_right;
							}
							else {
								parent->_right = cur->_right;
							}
						}
						else if (cur->_right == nullptr)
						{
							if (cur == parent->_left) {
								parent->_left = cur->_left;
							}
							else {
								parent->_right = cur->_left;
							}
						}
						//最右节点cur不一定是parent节点的右孩子
					   //parent->_right = cur->_left; ↑ why can't ? 
						delete cur;
					}
					return true;
				}
				return false;
			}

			bool Find(const Key& val) const
			{
				BST_Node* cur = _root;
				while (cur)
				{
					if (val < cur->_val) {
						cur = cur->_left;
					}
					else if (val > cur->_val) {
						cur = cur->_right;
					}
					else {
						return true;
					}
				}
				return false;
			}

			bool Empty() const
			{
				return _root == nullptr;
			}

			void Inorder() const
			{
				_InOrder(_root);
			}

		private:
			void _InOrder(BST_Node* root) const
			{
				if (!root) {
					return;
				}

				_InOrder(root->_left);
				cout << root->_val << ' ';
				_InOrder(root->_right);
			}

		private:
			BST_Node* _copyConstruct(BST_Node* root)
			{
				if (root == nullptr) {
					return nullptr;
				}

				BST_Node* cp_root = new BST_Node(root->_val);
				cp_root->_left = _copyConstruct(root->_left);
				cp_root->_right = _copyConstruct(root->_right);
				return cp_root;
			}

			void Destroy(BST_Node* root)
			{
				if (root == nullptr) {
					return;
				}

				Destroy(root->_left);
				Destroy(root->_right);
				delete root;
				root = nullptr;
			}

		private:
			BST_Node* _root;
		};
	}

	namespace key_value_model_tree
	{
		template<typename Key, typename Value>
		struct BinarySearchTreeNode
		{
			typedef BinarySearchTreeNode<Key, Value> BST_Node;

			BinarySearchTreeNode<Key, Value>(const Key& k, const Value& v)
				:_key(k), _val(v),
				_left(nullptr), _right(nullptr)
			{ }

			Key _key;
			Value _val;
			BST_Node* _left;
			BST_Node* _right;
		};

		template<typename Key, typename Value>
		class BinarySearchTree
		{
		private:
			typedef BinarySearchTreeNode<Key, Value> BST_Node;

		public:
			BinarySearchTree()
				:_root(nullptr)
			{ }

			~BinarySearchTree()
			{
				Destroy(_root);
			}

			bool Insert(const Key& key, const Value& val)
			{
				if (Empty()) {
					_root = new BST_Node(key, val);
				}
				BST_Node* cur = _root;
				BST_Node* parent = nullptr;
				while (cur)
				{
					if (key < cur->_key) {
						parent = cur;
						cur = cur->_left;
					}
					else if (key > cur->_key) {
						parent = cur;
						cur = cur->_right;
					}
					else {
						return false;
					}
				}
				BST_Node* newNode = new BST_Node(key, val);
				if (key < parent->_key) {
					parent->_left = newNode;
				}
				else {
					parent->_right = newNode;
				}
				return true;
			}

			bool Erase(const Key& key)
			{
				BST_Node* pos = _root;
				BST_Node* parent = nullptr;
				while (pos)
				{
					if (key < pos->_key) {
						parent = pos;
						pos = pos->_left;
					}
					else if (key > pos->_key) {
						parent = pos;
						pos = pos->_right;
					}
					else
					{
						if (pos->_left == nullptr)
						{
							if (pos == _root) {
								_root = pos->_right;
							}
							else
							{
								if (pos == parent->_left) {
									parent->_left = pos->_right;
								}
								else {
									parent->_right = pos->_right;
								}
							}
						}
						else if (pos->_right == nullptr)
						{
							if (pos == _root) {
								_root = pos->_left;
							}
							else
							{
								if (pos == parent->_left) {
									parent->_left = pos->_left;
								}
								else {
									parent->_right = pos->_left;
								}
							}
						}
						else
						{
							BST_Node* cur = pos->_left;
							BST_Node* parent = cur;
							while (cur->_right) {
								parent = cur;
								cur = cur->_right;
							}
							std::swap(cur->_key, pos->_key);
							std::swap(cur->_val, pos->_val);

							if (cur->_left == nullptr)
							{
								if (cur == parent->_left) {
									parent->_left = cur->_right;
								}
								else {
									parent->_right = cur->_right;
								}
							}
							else
							{
								if (cur == parent->_left) {
									parent->_left = cur->_left;
								}
								else {
									parent->_right = cur->_left;
								}
							}
						}
						return true;
					}
				}
				return false;
			}

			BST_Node* Find(const Key& key) const
			{
				BST_Node* cur = _root;
				while (cur)
				{
					if (key < cur->_key) {
						cur = cur->_left;
					}
					else if (key > cur->_key) {
						cur = cur->_right;
					}
					else {
						return cur;
					}
				}
				return nullptr;
			}

			bool Empty() const
			{
				return _root == nullptr;
			}

			void InOrder() const
			{
				_InOrder(_root);
			}

		private:
			void Destroy(BST_Node* root)
			{
				if (root == nullptr) {
					return;
				}

				Destroy(root->_left);
				Destroy(root->_right);
				delete root;
				root = nullptr;
			}

			void _InOrder(const BST_Node* root) const
			{
				if (root == nullptr) {
					return;
				}
				_InOrder(root->_left);
				cout << root->_val << ' ';
				_InOrder(root->_right);
			}

		private:
			BST_Node* _root;
		};
	}

	namespace key_value_model_tree_R
	{
		template<typename Key, typename Value>
		struct BinarySearchTreeNode
		{
			typedef BinarySearchTreeNode<Key, Value> BST_Node;

			BinarySearchTreeNode<Key, Value>(const Key& k, const Value& v)
				:_key(k), _val(v),
				_left(nullptr), _right(nullptr)
			{ }

			Key _key;
			Value _val;
			BST_Node* _left;
			BST_Node* _right;
		};

		template<typename Key, typename Value>
		class BinarySearchTree
		{
		private:
			typedef BinarySearchTreeNode<Key, Value> BST_Node;

		public:
			BinarySearchTree()
				:_root(nullptr)
			{ }

			~BinarySearchTree()
			{
				Destroy(_root);
			}

			bool Insert(const Key& key, const Value& val)
			{
				return _insert(key, val, _root);
			}

			bool Erase(const Key& key)
			{
				return _erase(key, _root);
			}

			BST_Node* Find(const Key& key) const
			{
				return _find(key, _root);
			}

			bool Empty() const
			{
				return _root == nullptr;
			}

			void InOrder() const
			{
				_InOrder(_root);
			}

		private:
			bool _erase(const Key& key, BST_Node*& root)
			{
				if (root == nullptr) {
					return false;
				}

				if (key < root->_key) {
					return _erase(key, root->_left);
				}
				else if (key > root->_key) {
					return _erase(key, root->_right);
				}
				else
				{
					BST_Node* delNode = root;
					if (root->_left == nullptr) {
						root = root->_right;
						delete delNode;
					}
					else if (root->_right == nullptr) {
						root = root->_left;
						delete delNode;
					}
					else
					{
						BST_Node* leftMax = root->_left;
						while(leftMax->_right) {
							leftMax = leftMax->_right;
						}
						std::swap(leftMax->_key, root->_key);
						std::swap(leftMax->_val, root->_val);

						return _erase(key, root->_left);
					}
					return true;
				}
			}

			bool _insert(const Key& key, const Value& val, BST_Node*& root)
			{
				if (root == nullptr)
				{
					root = new BST_Node(key, val);
					return true;
				}

				if (key < root->_key) {
					return _insert(key, val, root->_left);
				}
				else if (key > root->_key) {
					return _insert(key, val, root->_right);
				}
				else if (key == root->_key) {
					return false;
				}
			}

			BST_Node* _find(const Key& key, BST_Node* root) const
			{
				if (root == nullptr || key == root->_key) {
					return root;
				}

				BST_Node* ret_left = _find(key, root->_left);
				if (ret_left) {
					return ret_left;
				}
				BST_Node* ret_right = _find(key, root->_right);
				if (ret_right) {
					return ret_right;
				}
			}

			void Destroy(BST_Node* root)
			{
				if (root == nullptr) {
					return;
				}

				Destroy(root->_left);
				Destroy(root->_right);
				delete root;
				root = nullptr;
			}
			
			void _InOrder(const BST_Node* root) const
			{
				if (root == nullptr) {
					return;
				}
				_InOrder(root->_left);
				cout << root->_val << ' ';
				_InOrder(root->_right);
			}

		private:
			BST_Node* _root;
		};
	}
}