#pragma once

#include <algorithm>
#include "lterator.h"

namespace shr
{
	template<typename T>
	struct list_node
	{
		typedef list_node<T> Node;
		
		Node* _prev;
		Node* _next;
		T _val;

		list_node(const T& val)
			:_prev(nullptr),
			_next(nullptr),
			_val(val)
		{ }
	};

	template<typename T, typename Ref, typename Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<typename T, typename Ref, typename Ptr> Self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{ }

		Ref operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &(operator*());
		}

		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator++(int)
		{
			Self tmp = _node;
			_node = _node->_next;
			return tmp;
		}

		Self operator--(int)
		{
			Self tmp = _node;
			_node = _node->_prev;
			return tmp;
		}

		bool operator==(Self it)
		{
			return _node == it._node;
		}

		bool operator!=(Self it)
		{
			return _node != it._node;
		}
	};

	template<typename T>
	class list
	{
	private:
		typedef list_node<T> Node;

	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef shr::reverse_iterator<iterator, T&, T*> reverse_iterator;
		typedef shr::reverse_iterator<iterator, const T&, const T*> const_reverse_iterator;

	public:

		list()
		{
			empty_init();
		}

		template<typename InputIterator>
		list(InputIterator first, InputIterator end)
		{
			empty_init();
			while (first != end)
			{
				push_back(*first);
				++first;
			}
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
		{
			return _head;
		}

		reverse_iterator rbegin()
		{
			return end();
		}

		reverse_iterator rend()
		{
			return begin();
		}

		const_reverse_iterator rbegin() const
		{
			return end();
		}

		const_reverse_iterator rend() const
		{
			return begin();
		}

		void push_back(const T& val)
		{
			insert(end(), val);
		}

		void pop_back()
		{
			erase(--end());
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_front()
		{
			erase(begin());
		}

		size_t size()
		{
			return _size;
		}

		bool empty()
		{
			return _size == 0;
		}

		T& front()
		{
			return *begin();
		}

		T& back()
		{
			return *(--end());
		}

		void insert(iterator pos, const T& val)
		{
			Node* preNode = pos._node->_prev;
			Node* aimNode = pos._node;
			Node* newNode = new Node(val);
			preNode->_next = newNode;
			newNode->_prev = preNode;
			newNode->_next = aimNode;
			aimNode->_prev = newNode;
			++_size;
		}

		void erase(iterator pos)
		{
			Node* aimNode = pos._node;
			Node* preNode = pos._node->_prev;
			Node* nextNode = pos._node->_next;
			delete aimNode;
			preNode->_next = nextNode;
			nextNode->_prev = preNode;
			--_size;
		}

		void swap(list& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		void empty_init()
		{
			_head = new Node(0);
			_head->_prev = _head;
			_head->_next = _head;
			_size = 0;
		}

	private:
		Node* _head;
		size_t _size;
	};
}