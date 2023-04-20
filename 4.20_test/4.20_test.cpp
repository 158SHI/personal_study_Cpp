#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

inline int Max(int x, int y)
{
	return x > y ? x : y;
}

//int func()
//{
//	return 1;
//}

//void Test(int* arr, int sz)
//{
//	for (auto e : arr)
//	{
//
//	}
//}

int main()
{
	cout << Max(5, 10) << endl;
	//func();
	return 0;
}

//int main()
//{
//	//cout << Max(5, 10) << endl;
//
//	int arr[] = { 1,2,3,4,5,6 };
//	//Test(arr, 6);
//	for (auto e : arr) {
//		cout << e << ' ';
//	}
//	return 0;
//}

//int main()
//{
//	auto a = 10;
//	auto b = 3.14;
//	const auto c = "21121";
//
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//
//	return 0;
//}