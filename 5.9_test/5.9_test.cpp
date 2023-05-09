#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <assert.h>

using namespace std;

class MyStack
{
private:
	int _top;
	int _capacity;
	int* _a;

public:
	MyStack(int n)
		:_top(0),
		_capacity(n),
		_a((int*)malloc(sizeof(int)* n))
	{
		assert(_a);
	}

	~MyStack()
	{
		free(_a);
		_a = nullptr;
	}
};

class MyQueue
{
private:
	//声明
	MyStack _pushSt;
	MyStack _popSt;

public:
	MyQueue(int n)
		:_pushSt(n),//定义、初始化
		_popSt(n)
	{ }
};

//class A
//{
//private:
//	static int _count;
//
//public:
//	A()
//	{
//		++_count;
//	}
//
//	A(const A& a)
//	{
//		++_count;
//	}
//
//	~A()
//	{
//		--_count;
//	}
//
//	static int GetCount()
//	{
//		return _count;
//	}
//};
//
//int A::_count = 0;
//
//void test1()
//{
//	MyQueue q1(10);
//	MyQueue q2(10);
//	MyQueue q3 = 20; //先构造后拷贝构造。已被编译器优化，直接构造
//	const MyQueue& q4 = 20; //先构造，产生中间对象，该中间对象具有常属性
//}
//
//A g_a;
//
//void func()
//{
//	static A s_a;
//}
//
//void test2()
//{
//	cout << __LINE__ << ':' << A::GetCount() << endl; // 1
//	A a1;
//
//	func();
//	func();
//
//	cout << __LINE__ << ':' << A::GetCount() << endl; // 3
//
//}
//
//class B
//{
//private:
//	int _i;
//
//private:
//	B(int i)
//		:_i(i)
//	{ }
//
//public:
//	static B GetStackObj(int n = 10)
//	{
//		B b(n);
//		return b;
//	}
//
//	static B* GetHeapObj(int n = 10)
//	{
//		B* b = new B(n);
//		return b;
//	}
//
//	//void func()
//	//{
//
//	//}
//
//	//static void Func()
//	//{
//	//	func(); //无this指针，无法访问
//	//	B b(10);
//	//}
//};
//
//class C
//{
//private:
//	int _i;
//	double _d;
//
//public:
//	C(int i = 10, double d = 5.12)
//		:_i(i),
//		_d(d)
//	{ }
//};
//
//void test3()
//{
//	//B b1 = B::GetStackObj();
//	C c;
//}

//class A
//{
//private:
//   int a;
//
//public:
//   const int b;
//   float*& c;
//   static const char* d; //不通过初始化列表，在类外定义和初始化
//   static double* e; //不通过初始化列表，在类外定义和初始化
//
//public:
//	A(float* & pf, int& s_g)
//		:a(10),
//		b(10),
//		c(pf)
//	{
//		s_g = 50;
//	}
//};
//
//void test3()
//{
//
//}
//
//class B
//{
//private:
//	int _i;
//
//public:
//	B(int i)
//		:_i(i)
//	{ }
//};
//
//static B b(10);
//
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}

class Solution
{
private:
    int _year;
    int _month;
    int _day;

public:
    Solution(int year, int month, int day)
        :_year(year),
        _month(month),
        _day(day)
    { }

    int sumRet()
    {
        int _sumRet = 0;
        static int noLeap[] = { 0, 31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31 };
        static int Leap[] = { 0, 31, 29, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31 };

        if (((_year % 4 == 0) && (_year % 100 != 0)) ||
            (_year % 400 == 0))
        {
            for (int i = 1; i < _month; i++)
            {
                _sumRet += Leap[i];
            }
        }
        else
        {
            for (int i = 1; i < _month; i++)
            {
                _sumRet += noLeap[i];
            }
        }
        _sumRet += _day;

        return _sumRet;
    }
};

//int main()
//{
//    int year, month, day;
//    cin >> year >> month >> day;
//    Solution s(year, month, day);
//    return 0;
//}

int main()
{
	int date = 12132412;
	int year = 0;
	int month = 0;
	int day = 0;
	scanf("%4d%2d%2d", &year, &month, &day);
	return 0;
}