#define _CRT_SECURE_NO_WARNINGS 1

#include "unordered_set.h"
#include "unordered_map.h"
#include <iostream>

using namespace std;

//void test1()
//{
//	shr::unordered_set<int> s;
//	shr::unordered_map<int, int> m;
//	int arr[] = { 1, 7, 3, 9, 10 ,13, 29, 11, 23, 67, 20, 79 };
//	//for (auto e : arr) {
//	//	s.insert(e);
//	//}
//
//	for (auto e : arr) {
//		m.insert(make_pair(e, e));
//	}
//
//	pair<int, int>* ret = m.find(13);
//	if (ret) {
//		cout << ret->second << endl;
//	}
//}
//
//void test2()
//{
//	shr::unordered_set<int> s;
//	int arr[] = { 1, 7, 3, 9, 10 ,13, 29, 11, 23, 67, 20, 79 };
//	for (auto e : arr) {
//		s.insert(e);
//	}
//
//	//s.erase(79);
//	//s.erase(7);
//
//	shr::unordered_set<int>::iterator it = s.begin();
//	//cout << *it << endl;
//
//	//++it;
//	//cout << *it << endl;
//
//	while (it != s.end())
//	{
//		cout << *it << ' ';
//		++it;
//	}
//}

void test3()
{
	shr::unordered_map<string, int> m;
	int arr[] = { 1, 7, 3, 9, 10 ,13, 29, 11, 23, 67, 20, 79 };
	
	for (auto e : arr) {
		m.insert(make_pair(to_string(e), e));
	}

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->second << ' ';
		it++;
	}

	cout << endl;

	for (auto& e : m) {
		cout << e.first << ' ';
	}

	//auto ret = m.find("29");
	//cout << ret->second << endl;
}

void test4()
{
	shr::unordered_map<string, int> m;
	shr::unordered_set<string> s;
	int arr[] = { 1, 7, 3, 9, 10 ,13, 29, 11, 23, 67, 20, 79 };
	
	for (auto e : arr) {
		m.insert(make_pair(to_string(e), e));
	}

	for (auto e : arr) {
		s.insert(to_string(e));
	}

	shr::unordered_set<string>::iterator ret_s = s.find("13");
	cout << *ret_s << endl;
	
	shr::unordered_map<string, int>::iterator ret_m = m.find("67");
	cout << ret_m->second << endl;

	auto delRet = s.erase("13");
	if (delRet != s.end()) {
		cout << *delRet << endl;
	}
}

void test5()
{
	shr::unordered_set<int> s;
	shr::unordered_map<int, int> m;
	int arr[] = { 1, 7, 3, 9, 10 ,13, 29, 11, 23, 67, 20, 79 };
	//for (auto e : arr) {
	//	s.insert(e);
	//}
	//auto it = s.begin();
	//while (it != s.end())
	//{
	//	cout << *it << ' ';
	//	++it;
	//}

	for (auto e : arr)
	{
		//m.insert(make_pair(e, e));
		m[e] = e;
	}
	auto it = m.begin();
	
	while (it != m.end())
	{
		cout << it->second << ' ';
		++it;
	}
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	test5();
	return 0;
}