#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include "string.h"
#include <string>

using namespace std;

shr::string func()
{
	shr::string s("where are you from???");
	return s; //编译器会将具有将死特征的左值识别为右值
}

void test1()
{
	shr::string ret;
	ret = func(); //func()的返回值是一个右值将亡值
	//对ret进行移动赋值
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