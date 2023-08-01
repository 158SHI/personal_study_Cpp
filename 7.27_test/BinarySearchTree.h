#pragma once

#include <iostream>
#include <algorithm>

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
				_copyConstruct(BSTree._root);
			}

			Self& operator=(Self BSTree)
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

			BST_Node* Find(const Key& val)
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
						return cur;
					}
				}
				return nullptr;
			}

			bool Empty()
			{
				return _root == nullptr;
			}

			void Inorder()
			{
				_InOrder(_root);
			}

		private:
			void _InOrder(BST_Node* root)
			{
				if (!root) {
					return;
				}

				_InOrder(root->_left);
				cout << root->_val << ' ';
				_InOrder(root->_right);
			}

		private:
			void _copyConstruct(BST_Node* root)
			{

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

			bool Insert(const Key& val)
			{
				
			}

			bool Erase(const Key& val)
			{
				
			}

			BST_Node* Find(const Key& val)
			{
				
			}

			bool Empty()
			{
				return _root == nullptr;
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

		private:
			BST_Node* _root;
		};
	}
}