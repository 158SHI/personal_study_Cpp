#pragma once

#include <algorithm>

namespace shr
{
	template<typename Key, typename Value>
	struct BinarySearchTreeNode
	{
		typedef BinarySearchTreeNode<Key, Value> BST_Node;
		Key _key;
		Value _val;
		BST_Node* _left;
		BST_Node* _right;

		BinarySearchTreeNode(Key k, Value v)
			:_key(k), _val(v),
			_left(__nullptr), _right(nullptr)
		{ }
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

		bool insert(const Key& key, const Value& val)
		{
			BST_Node* newNode = new BST_Node(key, val);
			if (_root == nullptr)
			{
				_root = newNode;
				return true;
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
			if (key < parent->_key) {
				parent->_left = newNode;
			}
			else {
				parent->_right = newNode;
			}
			return true;
		}

		bool erase(const Key& key)
		{
			BST_Node* cur = _root;
			BST_Node* parent = nullptr;
			while (cur->_key != key)
			{
				if (key < cur->_key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else {
					return false;
				}
			}
			if (cur->_left != nullptr)
			{
				if (cur == _root) {
					_root = cur->_left;
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
				delete cur;
			}
			else if (cur->_right != nullptr)
			{
				if(cur == parent) { 
					_root = cur->_right;
				}
				else
				{
					if (cur == parent->_left) {
						parent->_left = cur->_right;
					}
					else {
						parent->_right = cur->_right;
					}
				}
				delete cur;
			}
			else
			{
				BST_Node* tmpPos = cur->_left;
				parent = tmpPos;
				while (tmpPos->_right)
				{
					parent = tmpPos;
					tmpPos = tmpPos->_right;
				}
				std::swap(tmpPos->_key, cur->_key);
				std::swap(tmpPos->_val, cur->_val);

				if (tmpPos->_left != nullptr)
				{
					if (tmpPos == parent->_left) {
						parent->_left = tmpPos->_left;
					}
					else {
						parent->_right = tmpPos->_left;
					}
				}
				else if (tmpPos->_right != nullptr)
				{
					if (tmpPos == parent->_left) {
						parent->_left = tmpPos->_right;
					}
					else {
						parent->_right = tmpPos->_right;
					}
				}
				delete tmpPos;
			}
			return true;
		}

		BST_Node* find(const Key& key)
		{

		}

		bool modify(const Key& key, const Value& val)
		{

		}

		~BinarySearchTree()
		{
			_destroy(_root);
		}

		void InOrder()
		{
			_InOrder(_root);
		}

	private:
		void _destroy(BST_Node* root)
		{
			if (root == nullptr) {
				return;
			}
			_destroy(root->_left);
			_destroy(root->_right);
			delete root;
			root = nullptr;
		}

		void _InOrder(BST_Node* root)
		{
			if (root == nullptr) {
				return;
			}
			_InOrder(root->_left);
			cout << root->_key << ' ';
			_InOrder(root->_right);
		}

	private:
		BST_Node* _root;
	};
}