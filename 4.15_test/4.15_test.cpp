#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//int Add(int x, int y)
//{
//	return x + y;
//}
//
//double Add(double x, double y)
//{
//	return x + y;
//}
//
//int main()
//{
//	/*cout << Add(1, 3) << endl;
//	cout << Add(1.3, 3.2) << endl;*/
//	int i = 0;
//	int& m = i;
//	int& n = m;
//	int& q = n;
//
//	cout << &i << endl;
//	cout << &m << endl;
//	cout << &n << endl;
//	cout << &q << endl;
//
//	return 0;
//}

int* CreatArr(int n = 5)
{
	int* pa = (int*)malloc(sizeof(int) * n);
	return pa;
}

int main()
{
	int* a = CreatArr(100);
	int* b = CreatArr();
	return 0;
}