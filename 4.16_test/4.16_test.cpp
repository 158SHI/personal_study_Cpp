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
//	int d; //Ĭ��ֵΪ0
//
//	int sum(int x, int y) {
//		return x + y;
//	}
//}
//
//int a = 20;//Ĭ��ֵΪ0
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
//	//int a; ����
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
//	int n; //Ĭ��Ϊ 0
//	int sum(int x, int y)
//	{
//		return x + y;
//	}
//}
//
////ȫ��չ��
//using namespace shr;
//
////ָ������
//using shr::sum;
//
//int main()
//{
//	//ָ������
//	int sum = shr::sum(2, 7);
//	cout << "sum = " << sum << endl;
//	return 0;
//}

////ȫȱʡ����
//void Func(int a = 10, int b = 20, int c = 30)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
////��ȱʡ������ȱʡ���������������θ���
//void Func(int a, int b = 10, int c = 20)
//{
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//
//const int default_capa = 10;
//
////ȱʡ������ֵ����Ϊ��������ȫ�ֱ���
//int* CreatArr(int n = default_capa)
//{
//	int* ret = (int*)malloc(sizeof(int) * n);
//	return ret;
//}

// 1.����������ͬ
int Sum(int a, int b)
{
	return a + b;
}

int Sum(int a, int b, int c)
{
	return a + b + c;
}

// 2.�������Ͳ�ͬ
double Sum(double x, int y)
{
	return x + y;
}

// 3.��������˳��ͬ
double Sum(int x, double y)
{
	return x + y;
}

int main()
{
	cout << Sum(3.4, 2) << endl;
	return 0;
}