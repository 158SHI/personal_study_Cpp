#pragma once

#include <utility>
#include <assert.h>

namespace shr
{
	enum Color
	{
		RED,
		BLACK
	};

	template<typename Key, typename Value>
	struct RB_tree_node
	{
		typedef RB_tree_node<Key, Value> node;
		
		std::pair<Key, Value> _kv;
		node* _left;
		node* _right;
		node* _parent;
		Color _color;

		RB_tree_node(const std::pair<Key, Value>& kv)
			:_kv(kv),
			_left(nullptr), _right(nullptr),
			_parent(nullptr),
			_color(RED)
		{ }
	};

	template<typename Key, typename Value>
	class RB_tree
	{
	private:
		typedef RB_tree_node<Key, Value> node;

	public:
		RB_tree()
			:_root(nullptr)
		{ }

		bool insert(const std::pair<Key, Value>& kv)
		{
			node* newNode = new node(kv);
			if (_root == nullptr)
			{
				_root = newNode;
				_root->_color = BLACK;
				return true;
			}

			node* cur = _root;
			node* parent = nullptr;
			while (cur)
			{
				if (kv.first < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (kv.first > cur->_kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else {
					return false;
				}
			}
			if (kv.first < parent->_kv.first) {
				parent->_left = newNode;
			}
			else {
				parent->_right = newNode;
			}
			newNode->_parent = parent;

			//调整平衡
			cur = newNode;
			parent = cur->_parent;
			while (parent && parent->_color == RED)
			{
				node* grandFather = parent->_parent;
				if (parent == grandFather->_left)
				{
					node* uncle = grandFather->_right;
					if (uncle && uncle->_color == RED)
					{
						parent->_color = uncle->_color = BLACK;
						grandFather->_color = RED;
						cur = grandFather;
						parent = cur->_parent;
					}
					else //uncle存在且为黑 或者 uncle不存在 
					{
						if (cur == parent->_left)
						{
							RotateRight(grandFather); //右单旋
							parent->_color = BLACK;
							grandFather->_color = RED;
						}
						else if (cur == parent->_right)
						{
							//右双旋
							RotateLeft(parent);
							RotateRight(grandFather);
							cur->_color = BLACK;
							grandFather->_color = RED;
						}
						else {
							assert(false);
						}
						break;
					}
				}
				else
				{
					node* uncle = grandFather->_left;
					if (uncle && uncle->_color == RED)
					{
						parent->_color = uncle->_color = BLACK;
						grandFather->_color = RED;
						cur = grandFather;
						parent = cur->_parent;
					}
					else
					{
						if (cur == parent->_right)
						{
							RotateLeft(grandFather);
							parent->_color = BLACK;
							grandFather->_color = RED;
						}
						else if (cur == parent->_left)
						{
							RotateRight(parent);
							RotateLeft(grandFather);
							cur->_color = BLACK;
							grandFather->_color = RED;
						}
						else {
							assert(false);
						}
						break;
					}
				}
			}
			_root->_color = BLACK;
			return true;
		}

		bool is_RB_tree()
		{
			//_root是黑色的
			//一个红色节点的父亲和两个孩子一定是黑色节点
			//从任意节点开始的路径中黑色节点数量相等
			if (_root->_color == RED) {
				return false;
			}

			node* cur = _root;
			int controlValue = 0;
			while (cur)
			{
				if (cur->_color == BLACK) {
					++controlValue;
				}
				cur = cur->_left;
			}
			int blackNum = 0;

			return _is_RB_tree(_root, controlValue, blackNum);
		}

		~RB_tree()
		{
			_destroy(_root);
		}

	private:
		bool _is_RB_tree(node* root, int controlValue, int blackNum)
		{
			//认为空树平衡
			if (root == nullptr) {
				return true;
			}

			if (root->_color == RED && root->_parent->_color == RED) {
				return false;
			}

			if (root->_color == BLACK) {
				++blackNum;
			}

			if (root->_left == nullptr && root->_right == nullptr && blackNum != controlValue) {
				return false;
			}

			return _is_RB_tree(root->_left, controlValue, blackNum) && 
				_is_RB_tree(root->_right, controlValue, blackNum);
		}

		void RotateLeft(node* parent)
		{
			node* cur = parent->_right;
			node* curLeft = cur->_left;
			node* ppNode = parent->_parent;
			parent->_right = cur->_left;
			cur->_left = parent;
			
			if (curLeft) {
				curLeft->_parent = parent;
			}
			parent->_parent = cur;

			if (ppNode == nullptr)
			{
				_root = cur;
				cur->_parent = nullptr;
			}
			else
			{
				if (parent == ppNode->_left) {
					ppNode->_left = cur;
				}
				else {
					ppNode->_right = cur;
				}
			}
		}

		void RotateRight(node* parent)
		{
			node* cur = parent->_left;
			node* curRight = cur->_right;
			node* ppNode = parent->_parent;

			parent->_left = curRight;
			cur->_right = parent;

			if (curRight) {
				curRight->_parent = parent;
			}
			parent->_parent = cur;

			if (ppNode == nullptr)
			{
				_root = cur;
				cur->_parent = nullptr;
			}
			else
			{
				if (parent == ppNode->_left) {
					ppNode->_left = cur;
				}
				else {
					ppNode->_right = cur;
				}
			}
		}

		void _destroy(node* root)
		{
			if (root == nullptr) {
				return;
			}

			_destroy(root->_left);
			_destroy(root->_right);
			delete root;
			root = nullptr;
		}

	private:
		node* _root;
	};
}