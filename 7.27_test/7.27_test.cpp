#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
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

int main()
{
	//BST_test1();
	BST_test2();
	return 0;
}