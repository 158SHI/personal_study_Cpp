#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "string.h"
#include <string>

using namespace std;

shr::string func()
{
	shr::string s("where are you from???");
	return s; //�������Ὣ���н�����������ֵʶ��Ϊ��ֵ
}

void test1()
{
	shr::string ret;
	ret = func(); //func()�ķ���ֵ��һ����ֵ����ֵ
	//��ret�����ƶ���ֵ
}

void test2()
{
	shr::string ret = func();
}

int main()
{
	test1();
	//test2();
	return 0;
}