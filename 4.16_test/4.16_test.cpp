#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

//namespace shr
//{
//	int a = 10;
//	int b = 20;
//	int c = a + b;
//	int d; //默认值为0
//
//	int sum(int x, int y) {
//		return x + y;
//	}
//}
//
//int a = 20;//默认值为0
//
//const int default_capa = 10;
//
//int* CreatArr(int n = ::a)
//{
//	int* ret = (int*)malloc(sizeof(int) * n);
//	return ret;
//}

//wrong
//int func(int a = 10, int b, int c = 20)
//{
//	return a + b + c;
//}

//int func(int a, int b = 10, int c = 20)
//{
//	return a + b + c;
//}

//int main()
//{
//	//int a; 报错
//	//cout << shr::c << endl;
//	//cout << ::a << endl;
//	//cout << shr::d << endl;
//	//cout << shr::sum(10, 10) << endl;
//	//int* a = CreatArr();
//	//free(a);
//
//	cout << func(2) << endl;
//	return 0;
//}

//int func(double a, double b)
//{
//	return a + b;
//}
//
//double func(double a, double b)
//{
//	return a + b;
//}
//
//int main()
//{
//	cout << func(3.2, 5.7) << endl;
//	return 0;
//}

//namespace shr
//{
//	namespace shr_A
//	{
//		int a = 10;
//		int b = 20;
//	}
//	namespace shr_B
//	{
//		int c = 13;
//		int d = -21;
//	}
//}

//namespace shr
//{
//	int n; //默认为 0
//	int sum(int x, int y)
//	{
//		return x + y;
//	}
//}
//
////全部展开
//using namespace shr;
//
////指定引入
//using shr::sum;
//
//int main()
//{
//	//指定访问
//	int sum = shr::sum(2, 7);
//	cout << "sum = " << sum << endl;
//	return 0;
//}

////全缺省函数
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
////半缺省函数，缺省参数从右往左依次给出
//void Func(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//const int default_capa = 10;
//
////缺省参数的值必须为常量或者全局变量
//int* CreatArr(int n = default_capa)
//{
//	int* ret = (int*)malloc(sizeof(int) * n);
//	return ret;
//}

// 1.参数个数不同
int Sum(int a, int b)
{
	return a + b;
}

int Sum(int a, int b, int c)
{
	return a + b + c;
}

// 2.参数类型不同
double Sum(double x, int y)
{
	return x + y;
}

// 3.参数类型顺序不同
double Sum(int x, double y)
{
	return x + y;
}

int main()
{
	cout << Sum(3.4, 2) << endl;
	return 0;
}