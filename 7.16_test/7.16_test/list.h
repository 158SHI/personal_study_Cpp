#pragma once

#include <assert.h>
#include "iterator.h"

namespace shr
{
	template<typename T>
	struct list_node
	{
		typedef list_node<T> Node;

		Node* _prev;
		Node* _next;
		T _val;

		list_node(const T& val = T())
			:_prev(nullptr),
			_next(nullptr),
			_val(val)
		{ }
	};

	template<typename T, typename Ref, typename Ptr>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
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
			return &_node->_val;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			__list_iterator<T> tmp = *this;
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
			__list_iterator<T> tmp = *this;
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
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
		typedef shr::reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;

	public:
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
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		const_reverse_iterator crbegin() const
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator crend() const
		{
			return reverse_iterator(begin());
		}

		list()
			:_size(0)
		{
			empty_init();
		}

		list(const list<T>& lt)
			:_size(0)
		{
			empty_init();
			for (auto& e : lt) {
				push_back(e);
			}
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void empty_init()
		{
			_head = new Node();
			_head->_prev = _head;
			_head->_next = _head;
		}

		void clear()
		{
			while (!empty()) {
				pop_back();
			}
		}

		bool empty() const
		{
			return _size == 0;
		}

		void push_back(const T& val)
		{
			insert(end(), val);
		}

		void pop_back()
		{
			assert(!empty());
			erase(--end());
		}

		void push_front(const T& val)
		{
			insert(begin(), val);
		}

		void pop_front()
		{
			assert(!empty());
			erase(begin());
		}

		// 在pos位置前插入值为val的节点
		iterator insert(iterator pos, const T& val)
		{
			Node* newNode = new Node(val);
			Node* aimNode = pos._node;
			Node* preNode = aimNode->_prev;
			preNode->_next = newNode;
			newNode->_prev = preNode;
			newNode->_next = aimNode;
			aimNode->_prev = newNode;
			++_size;
			return newNode;
		}

		// 删除pos位置的节点，返回该节点的下一个位置
		iterator erase(iterator pos)
		{
			assert(!empty());
			assert(pos != end());
			Node* aimNode = pos._node;
			Node* preNode = aimNode->_prev;
			Node* nextNode = aimNode->_next;
			delete aimNode;
			preNode->_next = nextNode;
			nextNode->_prev = preNode;
			--_size;
			return nextNode;
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		size_t size()
		{
			return _size;
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

	private:
		Node* _head;
		size_t _size;
	};
}
