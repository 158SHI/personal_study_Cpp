#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

int a;

namespace shr
{
	int b;
}

inline void func(int a = 20);

inline void func(int a, int b);

inline void func(int a)
{
	cout << a << endl;
}

inline void func(int a, int b)
{
	cout << a << ' ' << b << endl;
}

int main()
{
	//int c; //±¨´í
	//cout << ::a << ' ' << shr::b << ' ' << endl;
	/*func();
	func(21, 10);*/

	int arr[] = { 1, 3, 5, 7, 2, 4, 6, 8 };
	for (int& e : arr) {
		++e;
	}
	for (int e : arr) {
		cout << e << ' ';
	}
	return 0;
}