#pragma once

#include <utility>

namespace shr
{
	template<typename Key, typename Value>
	struct AVL_tree_node
	{
	private:
		typedef AVL_tree_node<Key, Value> AVLT_node;
	
	public:
		std::pair<Key, Value> _kv;
		AVLT_node* _left;
		AVLT_node* _right;
		AVLT_node* _parent;

		AVL_tree_node(std::pair<Key, Value> kv)
			:_kv(kv), 
			_left(nullptr), _right(nullptr), 
			_parent(nullptr)
		{ }
	};

	template<typename Key, typename Value>
	class AVL_tree
	{
	private:
		typedef AVL_tree_node<Key, Value> AVLT_node;


	public:
		AVL_tree()
			:_root(nullptr)
		{ }

		bool insert(const pair<Key, Value>& kv)
		{

		}

		~AVL_tree()
		{
			_destroy(_root);
		}

	private:
		void _destroy(AVLT_node* root)
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
		AVLT_node* _root;
	};
}