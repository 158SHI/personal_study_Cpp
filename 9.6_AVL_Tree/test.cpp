#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include "AVL_tree.h"

using namespace std;

void test1()
{
	shr::AVL_tree<int, string> tree;
	tree.insert(make_pair(9, "nine"));
	tree.insert(make_pair(12, "twelve"));
	tree.insert(make_pair(14, "fourteen"));
	tree.insert(make_pair(5, "five"));
	tree.insert(make_pair(10, "ten"));
	tree.insert(make_pair(15, "fifteen"));
}

void test2()
{
	shr::AVL_tree<int, string> tree;
	tree.insert(make_pair(14, "fourteen"));
	tree.insert(make_pair(12, "twelve"));
	tree.insert(make_pair(17, "seventeen"));
	tree.insert(make_pair(9, "nine"));
	tree.insert(make_pair(13, "thirteen"));
	tree.insert(make_pair(5, "five"));
}

void test3()
{
	shr::AVL_tree<int, string> tree;
	tree.insert(make_pair(90, "90"));
	tree.insert(make_pair(12, "60"));
	tree.insert(make_pair(10, "70"));
}

void test4()
{
	shr::AVL_tree<int, string> tree;
	pair<int, string> kv_arr[9] = { make_pair(16, "16"), make_pair(3, "3"), make_pair(7, "7"),
	make_pair(11, "11"), make_pair(9, "9"), make_pair(26, "26"), make_pair(18, "18"),
	make_pair(14, "14"), make_pair(15, "15") };
	for (auto& e : kv_arr) {
		tree.insert(e);
	}
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}