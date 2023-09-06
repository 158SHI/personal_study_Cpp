#pragma once

#include <assert.h>
#include "reverse_iterator.h"

namespace shr
{
	template<typename T>
	struct ListNode
	{
		typedef ListNode<T> Node;

		T _val;
		Node* _prev;
		Node* _next;

		ListNode(const T& val = T())
			:_val(val),
			_prev(nullptr),
			_next(nullptr)
		{ }
	};

	template<typename T, typename Ref, typename Ptr>
	struct __list_iterator
	{
		typedef __list_iterator<T, Ref, Ptr> self;
		typedef ListNode<T> Node;

		Node* _node;

		__list_iterator(Node* p)
			:_node(p)
		{ }

		Ref operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp = *this;
			_node = _node->_next;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp = *this;
			_node = _node->_prev;
			return tmp;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
		}

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}
	};

	template<typename T>
	class list
	{
	private:
		typedef ListNode<T> Node;

	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef shr::reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef shr::reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

	public:
		list()
		{
			_empty_init();
		}

		template<typename InputIterator>
		list(InputIterator first, InputIterator end)
		{
			_empty_init();
			while (first != end)
			{
				push_back(*first);
				++first;
			}
		}

		void _empty_init()
		{
			_head = new Node();
			_head->_next = _head->_prev = _head;
			_size = 0;
		}

		iterator begin()
		{
			return _head->_next;
		}

		const_iterator cbegin() const
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator cend() const
		{
			return _head;
		}

		reverse_iterator rbegin()
		{
			return end();
		}

		const_reverse_iterator crbegin() const
		{
			return cend();
		}

		reverse_iterator rend()
		{
			return begin();
		}

		const_reverse_iterator crend() const
		{
			return cbegin();
		}

		void push_back(const T& val)
		{
			insert(_head, val);
		}

		void push_front(const T& val)
		{
			insert(_head->_next, val);
		}

		void pop_back()
		{
			erase(_head->_prev);
		}

		void pop_front()
		{
			erase(_head->_next);
		}

		iterator insert(iterator pos, const T& val)
		{
			Node* newNode = new Node(val);
			Node* preNode = pos._node->_prev;
			preNode->_next = newNode;
			newNode->_prev = preNode;
			newNode->_next = pos._node;
			pos._node->_prev = newNode;
			++_size;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(!empty());
			assert(pos != _head);
			Node* aimNode = pos._node;
			Node* preNode = aimNode->_prev;
			Node* nextNode = aimNode->_next;
			delete aimNode;
			preNode->_next = nextNode;
			nextNode->_prev = preNode;
			--_size;
			return nextNode;
		}

		size_t size() const
		{
			return _size;
		}

		bool empty()
		{
			return size() == 0;
		}

		~list()
		{
			while (!empty()) {
				pop_back();
			}
			delete _head;
			_head = nullptr;
		}

	private:
		Node* _head;
		size_t _size;
	};
}