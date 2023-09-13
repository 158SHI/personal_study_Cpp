#define _CRT_SECURE_NO_WARNINGS 1

#include "my_set.h"
#include "my_map.h"
#include <set>
#include <iostream>

using namespace std;

//void test1()
//{
//	shr::set<int> s;
//	s.insert(5);
//	s.insert(1);
//	s.insert(4);
//	s.insert(7);
//	s.insert(9);
//
//	//shr::set<int>::iterator it = s.begin();
//	//while (it != s.end())
//	//{
//	//	if (*it == 7) {
//	//		int x = 10;
//	//	}
//	//	cout << *it << ' ';
//	//	++it;
//	//}
//	for (auto e : s) {
//		cout << e << ' ';
//	}
//}

void test2()
{
	shr::map<int, int> m;
	m.insert(make_pair(5, 5));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(4, 4));
	m.insert(make_pair(7, 7));
	m.insert(make_pair(9, 9));

	shr::map<int, int>::const_iterator cit = m.cbegin();
	while (cit != m.cend())
	{
		cout << cit->first << ' ';
		++cit;
	}
}

void test3()
{
	shr::map<int, int> m;
	for (int i = 10; i <= 16; ++i) {
		m[i] += 2;
	}
	for (auto& e : m)
	{
		cout << e.first << ' ';
		//cout << e.second << ' ';
	}
}

int main()
{
	//test1();
	test2();
	//test3();
	return 0;
}