#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

/*
�����ռ䣺���C�����е�������Ⱦ����
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
//	printf("%d\n", a); //���ھֲ�����Ѱ��
//	printf("%d\n", ::a); //ָ����ȫ������Ѱ��
//	printf("%d\n", shr::a); //ָ���������ռ�����Ѱ��
//	return 0;
//}

#include <iostream>

//����չ�������ռ���
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