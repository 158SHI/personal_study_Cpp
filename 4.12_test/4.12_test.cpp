#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
命名空间：解决C语言中的命名污染问题
*/

//namespace shr
//{
//	int a = 10;
//}
//
//int a = 20;
//
////using namespace shr;
//
//int main()
//{
//	int a = 30;
//	printf("%d\n", a); //先在局部域中寻找
//	printf("%d\n", ::a); //指定在全局域中寻找
//	printf("%d\n", shr::a); //指定在命名空间域中寻找
//	return 0;
//}

#include <iostream>

//部分展开命名空间域
using std::cin;
using std::cout;
using std::endl;

namespace shr
{
	int a = 0;
}

namespace shr
{
	namespace shr_A
	{
		int b = 35;
	}

	namespace shr_B
	{
		int b = 45;
	}
}

int main()
{
	int a = 0;
	cin >> a;
	cin >> shr::a;

	cout << a << endl;
	cout << shr::a << endl;

	cout << shr::shr_A::b << ' ' << shr::shr_B::b << endl;
	return 0;
}