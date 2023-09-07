#pragma once

#include <utility>
#include <assert.h>

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
		int _bf; //balance factor

		AVL_tree_node(std::pair<Key, Value> kv)
			:_kv(kv), 
			_left(nullptr), _right(nullptr), 
			_parent(nullptr),
			_bf(0)
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

		bool insert(const std::pair<Key, Value>& kv)
		{
			AVLT_node* newNode = new AVLT_node(kv);
			if (_root == nullptr)
			{
				_root = newNode;
				return true;
			}

			Key key = kv.first;
			AVLT_node* cur = _root;
			AVLT_node* parent = nullptr;
			while (cur)
			{
				if (key < cur->_kv.first)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (key > cur->_kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else {
					return false;
				}
			}
			if (key < parent->_kv.first) {
				parent->_left = newNode;
			}
			else {
				parent->_right = newNode;
			}
			newNode->_parent = parent;
			cur = newNode;

			//更新和检查平衡因子
			while (parent)
			{
				//更新平衡因子
				if (cur == parent->_left) {
					parent->_bf--;
				}
				else {
					parent->_bf++;
				}

				//检查平衡因子
				if (parent->_bf == 0) {
					break;
				}
				else if (parent->_bf == 1 || parent->_bf == -1)
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if (parent->_bf == 2 || parent->_bf == -2) //需要做平衡处理
				{
					if (parent->_bf == 2 && cur->_bf == 1) {
						RotateToLeft(parent); //左单旋
					}
					else if (parent->_bf == -2 && cur->_bf == -1) {
						RotateToRight(parent); //右单旋
					}
					else if (parent->_bf == 2 && cur->_bf == -1) {
						RotateRightLeft(parent); //左双旋
					}
					else { //(parent->_bf == -2 && cur->_bf == 1)
						RotateLeftRight(parent); //右双旋
					}
					break; //旋转后退出调整和检查
				}
				else {
					assert(false);
				}
			}
			return true;
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

		void RotateToLeft(AVLT_node* parent)
		{
			AVLT_node* cur = parent->_right;
			AVLT_node* curLeftNode = cur->_left;
			AVLT_node* ppNode = parent->_parent;

			parent->_right = curLeftNode;
			cur->_left = parent;
			cur->_bf = parent->_bf = 0;
			//更新父节点
			parent->_parent = cur;
			if (curLeftNode) {
				curLeftNode->_parent = parent;
			}
			//重新链到AVL树
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

		void RotateToRight(AVLT_node* parent)
		{
			AVLT_node* cur = parent->_left;
			AVLT_node* curRight = cur->_right;
			AVLT_node* ppNode = parent->_parent;

			parent->_left = curRight;
			cur->_right = parent;
			cur->_bf = parent->_bf = 0;

			parent->_parent = cur;
			if (curRight) {
				curRight->_parent = parent;
			}

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

		void RotateRightLeft(AVLT_node* parent)
		{
			AVLT_node* cur = parent->_right;
			AVLT_node* curLeft = cur->_left;
			int curLeftBf = curLeft->_bf; //根据curLeftBf的旧bf值调整各个节点的bf值

			//复用接口时，会将三个转折处的节点的bf一律修改为 0
			//这是不完全正确的，需要分情况对三个关键节点的bf值进行修正
			RotateToRight(parent->_right);
			RotateToLeft(parent);

			if (curLeftBf == 0)
			{
				parent->_bf = 0;
				cur->_bf = 0;
				curLeft = 0;
			} //新节点插入到curLeft的左边
			else if (curLeftBf == -1)
			{
				cur->_bf = 1;
				parent->_bf = 0;
				curLeft->_bf = 0;
			} //新节点插入到curLeft的右边
			else if (curLeftBf == 1)
			{
				parent->_bf = -1;
				cur->_bf = 0;
				curLeft->_bf = 0;
			}
			else {
				assert(false);
			}
		}

		void RotateLeftRight(AVLT_node* parent)
		{
			AVLT_node* cur = parent->_left;
			AVLT_node* curRight = cur->_right;
			int curRightBf = curRight->_bf;

			RotateToLeft(parent->_left);
			RotateToRight(parent);

			if (curRightBf == 0)
			{
				cur->_bf = 0;
				parent->_bf = 0;
				curRight->_bf = 0;
			}
			else if (curRightBf == 1)
			{
				cur->_bf = -1;
				parent->_bf = 0;
				curRight->_bf = 0;
			}
			else if (curRightBf == -1)
			{
				cur->_bf = 0;
				parent->_bf = 1;
				curRight->_bf = 0;
			}
			else {
				assert(false);
			}
		}

	private:
		AVLT_node* _root;
	};
}