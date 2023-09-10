#define _CRT_SECURE_NO_WARNINGS 1

#include "RB_tree.h"
#include <iostream>
#include <vector>

using namespace std;

void test1()
{
	shr::RB_tree<int, int> tree;
	vector<int> v{ 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : v)
	{
		tree.insert(make_pair(e, e));
	}
}

void test2()
{
	shr::RB_tree<int, int> tree;
	vector<int> v{ 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	for (auto e : v)
	{
		tree.insert(make_pair(e, e));
		cout << "insert: " << e << ", is_RB_tree: " << tree.is_RB_tree() << endl;
	}
}

int main()
{
	//test1();
	test2();
	return 0;
}