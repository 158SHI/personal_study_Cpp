#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

class A
{
public:
	virtual void func1()
	{

	}
};

class B : virtual public A
{
public:
	virtual void func1()
	{

	}
};

class C : virtual public A
{
public:
	virtual void func1()
	{

	}
};

class D : public B, public C
{
public:
	virtual void func1()
	{

	}
};

void BST_test1()
{
	shr::key_model_tree::BinarySearchTree<int> tree;
	//tree.Insert(8);
	//tree.Insert(6);
	//tree.Insert(12);
	//tree.Insert(3);
	//tree.Insert(7);
	//tree.Insert(10);
	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : arr) {
		tree.Insert(e);
	}

	tree.Inorder();
}

void BST_test2()
{
	shr::key_model_tree::BinarySearchTree<int> tree;
	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : arr) {
		tree.Insert(e);
	}

	//if (shr::BinarySearchTreeNode<int>* ret = tree.Find(10)) {
	//	cout << ret->_val << endl;
	//}

	//tree.Erase(1);
	//tree.Inorder();
	//cout << endl;

	//tree.Erase(3);
	//tree.Inorder();
	//cout << endl;

	//tree.Erase(10);
	//tree.Inorder();
	//cout << endl;

	//tree.Erase(13);
	//tree.Inorder();
	//cout << endl;

	//tree.Erase(10);
	//tree.Erase(14);
	//tree.Erase(13);
	//
	//tree.Inorder();
	//cout << endl;

	//tree.Erase(8);
	//tree.Inorder();
	//cout << endl;

	tree.Erase(3);
	tree.Inorder();
	cout << endl;

	tree.Erase(6);
	tree.Inorder();
	cout << endl;
}

void BST_test3()
{
	shr::key_model_tree::BinarySearchTree<int> tree;
	int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto e : arr) {
		tree.Insert(e);
	}

	shr::key_model_tree::BinarySearchTree<int> tree_2(tree);
	tree.Inorder();
	cout << endl;
	tree_2.Inorder();
}

void BST_test4()
{
	shr::key_value_model_tree::BinarySearchTree<std::string, std::string> tree;
	tree.Insert("abandon", "vt. 放弃；丢弃，抛弃");
	tree.Insert("ability", "n. 能力， 本领；才能，才干");
	tree.Insert("digital", "a. 数字的");
	tree.Insert("dilemma", "n. 窘境，困境");
	tree.Insert("inspire", "n. 鼓舞人心的人(事)");
	tree.Insert("insist", "v. 坚持，主张");

	//string key;
	//while (cin >> key)
	//{
	//	auto ret = tree.Find(key);
	//	if (ret) {
	//		cout << ret->_val << endl;
	//	}
	//}
	
	//tree.InOrder();

	tree.Erase("inspire");
	tree.Erase("abandon");

	tree.InOrder();
}

void BST_Node5()
{
	//int arr[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	shr::key_value_model_tree_R::BinarySearchTree<int, string> tree;
	tree.Insert(8, "eight");
	tree.Insert(3, "three");
	tree.Insert(1, "one");
	tree.Insert(10, "ten");
	tree.Insert(6, "six");
	tree.Insert(4, "four");
	tree.Insert(7, "seven");
	tree.Insert(14, "fourteen");
	tree.Insert(13, "thirteen");

	//tree.InOrder();
	//if (auto ret = tree.Find(11)) {
	//	cout << ret->_val << endl;
	//}
	//tree.Erase(7);
	//tree.Erase(6);
	tree.Erase(6);
	tree.InOrder();
}

int main()
{
	//BST_test1();
	//cout << endl;
	//BST_test2();
	//BST_test3();
	//BST_test4();
	BST_Node5();
	return 0;
}