#define _CRT_SECURE_NO_WARNINGS 1

#include "hash_table.h"
#include <iostream>

using namespace std;

void test1()
{
	shr::HashBucket::hash_table<int, int> t;
	int arr[] = { 1, 7, 3, 9, 10 ,13, 29, 11, 23, 67, 20, 79 };
	for (auto e : arr) {
		t.insert(make_pair(e, e));
	}

	//pair<int, int>* ret = t.find(100);
	//if (ret) {
	//	cout << ret->second << endl;
	//}

	t.erase(13);
	t.erase(29);
}

int main()
{
	test1();
	return 0;
}