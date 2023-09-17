#define _CRT_SECURE_NO_WARNINGS 1

#include "unordered_set.h"
#include "unordered_map.h"
#include <iostream>

using namespace std;

void test1()
{
	shr::unordered_set<int> s;
	shr::unordered_map<int, int> m;
	int arr[] = { 1, 7, 3, 9, 10 ,13, 29, 11, 23, 67, 20, 79 };
	//for (auto e : arr) {
	//	s.insert(e);
	//}

	for (auto e : arr) {
		m.insert(make_pair(e, e));
	}

	pair<int, int>* ret = m.find(13);
	if (ret) {
		cout << ret->second << endl;
	}
}

int main()
{
	test1();
	return 0;
}