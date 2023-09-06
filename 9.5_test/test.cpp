#define _CRT_SECURE_NO_WARNINGS 1

using namespace std;

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "list.h"
#include "BinarySearchTree.h"

void test1()
{
	shr::list<int> l;
	//l.push_back(1);
	//l.push_back(2);
	//l.push_back(3);
	//l.push_back(4);
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	for(auto e : l) {
		cout << e << ' ';
	}
	cout << endl;

	l.pop_back();
	l.pop_back();
	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;

	l.pop_front();
	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;
}

void test2()
{
	shr::list<int> l;
	//l.push_back(1);
	//l.push_back(2);
	//l.push_back(3);
	//l.push_back(4);
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;

	l.insert(++l.begin(), 10);
	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;

	l.erase(++l.begin());
	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;
}

void test3()
{
	shr::list<int> l;
	//l.push_back(1);
	//l.push_back(2);
	//l.push_back(3);
	//l.push_back(4);
	shr::list<int>::reverse_iterator rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << ' ';
		rit++;
	}
}

void test4()
{
	vector<int> v{ 1, 2, 3, 4 };
	const shr::list<int> l(v.begin(), v.end());
	auto crit = l.crbegin();
	while (crit != l.crend())
	{
		cout << *crit << ' ';
		++crit;
	}
	cout << endl;
}

void test_list()
{
	//test1();
	//test2();
	//test3();
	test4();
}

void BST_test1()
{
	shr::BinarySearchTree<int, string> t;
	t.insert(3, "three");
	t.insert(1, "one");
	t.insert(5, "five");
	t.insert(2, "two");
	t.InOrder();
}

void test_BinarySearchTree()
{
	BST_test1();
}

int main()
{
	test_BinarySearchTree();
	return 0;
}