#pragma once

#include <utility>
#include <assert.h>
#include <iostream>
#include "reverse_iterator.h"

namespace shr
{
	enum Color
	{
		RED,
		BLACK
	};

	template<typename T>
	struct RB_tree_node
	{
		typedef RB_tree_node<T> node;
		
		T _data;
		node* _left;
		node* _right;
		node* _parent;
		Color _color;

		RB_tree_node(const T& data)
			:_data(data),
			_left(nullptr), _right(nullptr),
			_parent(nullptr),
			_color(RED)
		{ }
	};

	template<typename T, typename Ref, typename Ptr>
	class __RB_tree_iterator
	{
	private:
		typedef RB_tree_node<T> node;
		typedef __RB_tree_iterator<T, Ref, Ptr> Self;
		typedef __RB_tree_iterator<T, T&, T*> iterator;

	public:
		__RB_tree_iterator(node* pnode)
			:_node(pnode)
		{ }

		__RB_tree_iterator(const iterator& it)
			:_node(it._node)
		{ }

		Ref operator*() const
		{
			return _node->_data;
		}

		Ptr operator->() const
		{
			return &(_node->_data);
		}

		bool operator==(const Self& it) const
		{
			return _node == it._node;
		}

		bool operator!=(const Self& it) const
		{
			return _node != it._node;
		}

		Self& operator++()
		{
			node* cur = _node;
			node* parent = cur->_parent;
			
			if (cur->_right)
			{
				node* subLeft = cur->_right;
				while (subLeft->_left) {
					subLeft = subLeft->_left;
				}
				_node = subLeft;
			}
			else
			{
				while (parent)
				{
					if (cur == parent->_left) {
						break;
					}
					else
					{
						cur = cur->_parent;
						parent = parent->_parent;
					}
				}
				_node = parent;
			}
			return *this;
		}

		Self operator++(int)
		{
			Self tmp = *this;
			++(*this);
			return tmp;
		}

		Self& operator--()
		{
			node* cur = _node;
			node* parent = cur->_parent;
			if (cur->_left)
			{
				node* subRight = cur->_left;
				while (subRight->_right) {
					subRight = subRight->_right;
				}
				_node = subRight;
			}
			else
			{
				while (parent && cur == parent->_left)
				{
					if (cur == parent->_right) {
						break;
					}
					else
					{
						cur = cur->_parent;
						parent = parent->_parent;
					}
				}
				_node = parent;
			}
			return *this;
		}

		Self operator--(int)
		{
			Self tmp = *this;
			--(*this);
			return tmp;
		}

		node* _node;
	};

	template<typename Key, typename T, typename KeyOfT>
	class RB_tree
	{
	private:
		typedef RB_tree_node<T> node;
	
	public:
		typedef __RB_tree_iterator<T, T&, T*> iterator;
		typedef __RB_tree_iterator<T, const T&, const T*> const_iterator;
		//typedef shr::reverse_iterator<iterator, T&, T*> reverse_iterator;
		//typedef shr::reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

	public:
		RB_tree()
			:_root(nullptr)
		{ }

		iterator begin()
		{
			node* leftMost = _root;
			while (leftMost && leftMost->_left) {
				leftMost = leftMost->_left;
			}
			return leftMost;
		}

		const_iterator begin() const
		{
			node* leftMost = _root;
			while (leftMost && leftMost->_left) {
				leftMost = leftMost->_left;
			}
			return leftMost;
		}

		iterator end()
		{
			return nullptr;
		}

		const_iterator end() const
		{
			return nullptr;
		}

		iterator find(const Key& k) const
		{
			node* cur = _root;
			KeyOfT kot;
			while (cur)
			{
				if (k < kot(cur->_data)) {
					cur = cur->_left;
				}
				else if (k > kot(cur->_data)) {
					cur = cur->_right;
				}
				else {
					return cur;
				}
			}
			return nullptr;
		}

		std::pair<iterator, bool> insert(const T& data)
		{
			node* newNode = new node(data);
			if (_root == nullptr)
			{
				_root = newNode;
				_root->_color = BLACK;
				return std::make_pair(_root, true);
			}
			KeyOfT kot;
			node* cur = _root;
			node* parent = nullptr;
			while (cur)
			{
				if ((kot(data)) < (kot((cur->_data))))
				{
					parent = cur;
					cur = cur->_left;
				}
				else if ((kot(data)) > (kot((cur->_data))))
				{
					parent = cur;
					cur = cur->_right;
				}
				else {
					return std::make_pair(cur, false);
				}
			}
			if (kot(data) < kot(parent->_data)) {
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
			return std::make_pair(newNode, true);
		}

		bool is_RB_tree() const
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

			parent->_right = curLeft;
			cur->_left = parent;
			
			if (curLeft) {
				curLeft->_parent = parent;
			}
			parent->_parent = cur;

			if (parent == _root)
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
				cur->_parent = ppNode;
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
				cur->_parent = ppNode;
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