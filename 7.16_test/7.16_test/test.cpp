#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <list>
#include <vector>

#include "list.h"

using namespace std;

void test1()
{
	shr::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;

	l.pop_back();
	l.pop_back();
	l.pop_back();
	//l.pop_back();
	//l.pop_back();

	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;

	l.push_front(10);
	l.push_front(20);
	l.push_front(30);
	l.push_front(40);

	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;

	l.pop_front();
	l.pop_front();
	l.pop_front();

	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;
}

void test2()
{
	shr::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	auto it = l.begin();
	for ( ; it != l.end(); ++it)
	{
		if (*it == 3) {
			break;
		}
	}
	if (it != l.end())
	{
		l.erase(it);
	}
	l.insert(l.begin(), 50);
	l.insert(l.end(), 80);

	l.erase(l.begin());
	l.erase(--l.end());

	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;
}

void test3()
{
	shr::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	shr::list<int> l2(l);
	for (auto e : l2) {
		cout << e << ' ';
	}
	cout << endl;

	l2.push_back(19);
	l2.push_back(29);
	l2.push_back(39);

	l.swap(l2);

	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;

	for (auto e : l2) {
		cout << e << ' ';
	}
	cout << endl;
}

int main()
{
	//list<int> l1;
	//list<int> l2;
	////l1.resize(10);
	////for (auto e : l1) {
	////	cout << e << ' ';
	////}
	////cout << endl;
	//for (int i = 1; i <= 3; ++i) {
	//	l1.push_back(i);
	//}

	//for (int i = 1; i <= 3; ++i) {
	//	l2.push_back(i * 10);
	//}

	//l1.splice(l1.begin(), l2);

	//for (auto e : l1) {
	//cout << e << ' ';
	//}
	//cout << endl;

	//for (auto e : l2) {
	//	cout << e << ' ';
	//}
	//cout << endl;

	//test1();
	//test2();
	test3();
	return 0;
}