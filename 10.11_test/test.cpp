#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <initializer_list>
#include <vector>

using namespace std;

//template<class T1, class T2>
//void func(T1 x, T2 y)
//{
//	decltype(x, y) ret = x * y;
//	cout << typeid(ret).name() << endl;
//}

void test1()
{
	//func(9.2, 9);
}

void func(int x)
{
	cout << "void func(int x)" << endl;
}

void func(int* x)
{
	cout << "void func(int* x)" << endl;
}

class A
{
public:
	virtual void func()
	{
		cout << "A::func()" << endl;
	}
};

class B : public A
{
public:
	virtual void func() override
	{
		cout << "B::func()" << endl;
	}
};

class C : public B
{
public:
	virtual void func()
	{
		cout << "C::func()" << endl;
	}
};

void test2()
{
	func(NULL);
	func(nullptr);
	cout << typeid(NULL).name() << endl;
	cout << typeid(nullptr).name() << endl;
}

void test3()
{
	//vector<int> v{ 1,2,3 };
	initializer_list<int> il{ 1, 2, 3 };
	vector<int> v(il);
}

void test4()
{
	int a = 10; //10是右值
	int b = a; //a和b都是左值
	int sum = a + b;// a + b是右值

	const char* p = "hello"; //"hello"是左值
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}