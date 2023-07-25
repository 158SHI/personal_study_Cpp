#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class A
{
public:
	A()
		:_a(0)
	{ }

	virtual void func()
	{
		cout << "A::func()" << endl;
	}

protected:
	int _a;
};

class B : public A
{
public:
	virtual void func()
	{
		cout << "B::func()" << endl;
	}

	void func2()
	{
		cout << _a << endl;
	}
};

void func(A& a)
{
	a.func();
}

void test1()
{
	A a;
	B b;
	//a = b;
	//此处表明对象直接复制进行切片拷贝时，不拷贝虚函数表
	func(a);
	func(b);
	//func(b);
	//func(a);
}

class Base1
{
public:
	virtual void func1()
	{
		cout << "Base1::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "Base1::func2()" << endl;
	}
};

class Base2
{
public:
	virtual void func1()
	{
		cout << "Base2::func1()" << endl;
	}

	virtual void func2()
	{
		cout << "Base2::func2()" << endl;
	}
};

class Div : public Base1, public Base2
{
public:
	virtual void func1()
	{
		cout << "Div::func1()" << endl;
	}

	virtual void func3()
	{
		cout << "Div::func3()" << endl;
	}

	int _a;
};

void test2()
{
	Div div;
	Base2& Bs2 = div;
	Bs2.func1();
}

int main()
{
	//test1();
	test2();
	return 0;
}