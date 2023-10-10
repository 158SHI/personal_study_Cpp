#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "smart_ptr.h"

using namespace std;

struct MyStruct
{
	MyStruct()
	{
		cout << "MyStruct()" << endl;
	}

	~MyStruct()
	{
		cout << "~MyStruct()" << endl;
	}

	int _i = 12;
	char _c = 'a';
};

//deleteºÍdelete[]
void test1()
{
	//char* str = new char[10] {'1', '2'};
	//delete[] str;

	//int* pi = new int(10);
	////delete[] pi;

	//int* pa = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//delete[] pa;
	MyStruct* pa = new MyStruct[10];

	cout << *((int*)pa - 1) << endl;

	delete[] pa;
}

void test2()
{
	shr::unique_ptr<int> p1(new int(10));
	shr::unique_ptr<int> p2(new int(20));
	//p1 = p2;
}

struct Node
{
	int _d;
	shr::weak_ptr<Node> _next;
	shr::weak_ptr<Node> _prev;
};

void test3()
{
	shr::shared_ptr<Node> node1(new Node);
	shr::shared_ptr<Node> node2(new Node);
	node1->_next = node2;
	node2->_prev = node1;
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}