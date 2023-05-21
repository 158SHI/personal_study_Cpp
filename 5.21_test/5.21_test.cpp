#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

void test1()
{
	int a = 10;
	int b = 20;
	cout << &a << endl;
	cout << &b << endl;
}

void test2()
{
	int* p = new int[10];
	operator delete(p);
}

//int main()
//{
//	test1();
//	test2();
//	return 0;
//}

class A
{
public:
	A()
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
};

class B
{
public:
	B()
	{
		cout << "B()" << endl;
	}

	~B()
	{
		cout << "~B()" << endl;
	}
};

class C
{
public:
	C()
	{
		cout << "C()" << endl;
	}

	~C()
	{
		cout << "~C()" << endl;
	}

};

class D
{
public:
	D()
	{
		cout << "D()" << endl;
	}

	~D()
	{
		cout << "~D()" << endl;
	}
};

//C c;

//void main()
//{
//	//A* pa = new A();
//	//B b;
//	//static D d;
//	//delete pa;
//
//	////A* pA = new A[5];
//	////delete[] pA;
//
//	//int* p = new int[10];
//	//delete p;
//
//	int a = 10;
//	int b = 20;
//
//	cout << &a << endl;
//	cout << &b << endl;
//}

int main()
{
	int* parr = new int[5];
	delete[] parr;

	A* pA = new A[3];
	//delete pA; //程序崩溃
	delete[] pA;
	
	//delete pA;
	//(pA + 1)->~A();
	//(pA + 2)->~A();

	return 0;
}