#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"
#include <iostream>
#include <array>

using namespace std;

void test1()
{
	shr::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	l.push_front(10);
	l.push_front(9);
	l.push_front(8);

	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;

	l.pop_back();
	l.pop_back();
	l.pop_back();

	l.pop_front();
	l.pop_front();

	for (auto e : l) {
		cout << e << ' ';
	}
	cout << endl;

	cout << l.front() << endl;
	cout << l.back() << endl;
}

void test2()
{
	shr::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	auto rit = l.rbegin();
	while (rit != l.rend())
	{
		cout << *rit << ' ';
		++rit;
	}
}

template<typename T, size_t N>
void func()
{
	T* p = new T[N];
	delete[] p;
}

void test3()
{
	func<int, 10>();
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}