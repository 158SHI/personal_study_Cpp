#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//class Solution
//{
//private:
//    int _i;
//    int _ret;
//
//private:
//    class Tmp
//    {
//    public:
//        Tmp()
//        { }
//
//        void func(const Solution& s)
//        {
//            cout << s._i << endl;
//        }
//    };
//
//public:
//    int Sum_Solution(int n)
//    {
//        Solution::Tmp a[n];
//        return _ret;
//    }
//};

//class Tmp
//{
//    Solution s;
//public:
//    Tmp()
//    { }
//
//    void func()
//    {
//        s._i = 10;
//    }
//};



//int Solution::_i = 1;
//int Solution::_ret = 0;

//int main()
//{
//    Solution s;
//    return 0;
//}


//class Time
//{
//	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		// 直接访问时间类私有的成员变量
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};

class MyStack
{
	friend int GetTop(const MyStack& s);

private:
	int* _a;
	int _top;
	int _capa;

public:
	MyStack(int top, int capa)
		:_top(top),
		_capa(capa)
	{ }

	void func1()
	{
		
	}

	void func2()
	{
		func1();
	}
};

//class MyQueue
//{
//private:
//	MyStack pushSt;
//	MyStack popSt;
//
//public:
//	MyQueue()
//		:pushSt(10, 20),
//		popSt(10, 20)
//	{ }
//};

//int GetTop(const MyStack& s)
//{
//	return s._top;
//}
//
//
//int globalVar = 1;
//
//static int staticGlobalVar = 1;
//
//void Test()
//
//{
//
//	static int staticVar = 1;
//
//	int localVar = 1;
//
//
//
//	int num1[10] = { 1, 2, 3, 4 };
//
//	char char2[] = "abcd";
//
//	const char* pChar3 = "abcd";
//
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//
//	free(ptr1);
//
//	free(ptr3);
//
//}
//
//int main()
//{
//	//MyQueue q;
//	MyStack s(10, 20);
//	
//	return 0;
//}

class Date
{
private:
	int _year;
	int _month;
	int _day;

public:
	Date(int year = 1840, int month = 6, int day = 1)
		:_year(year),
		_month(month),
		_day(day)
	{ }


};

//int main()
//{
//	Date d;
//	return 0;
//}

//class MyStack
//{
//private:
//	int* _a;
//	int _top;
//	int _capacity;
//
//public:
//	MyStack(int top = 0, int capacity = 10)
//		:_top(top),
//		_capacity(capacity)
//	{
//
//	}
//};


class A
{
public:
	A(int a)
		:_a(a), //再初始化_a
		_b(_a) //先初始化_b
	{ }
	void Print()
	{
		cout << _a << " " << _b << endl;
	}
private:
	int _b;
	int _a;
};

//int main()
//{
//	A a(1);
//	a.Print();
//}

//面试题：实现一个类，计算程序中创建出了多少个类对象
class B
{

private:
	static int _count;


public:
	static int GetCount()
	{
		return _count;
	}


	B()
	{
		++_count;
	}

	B(const B& b)
	{
		++_count;
	}

	~B()
	{
		--_count;
	}


};

int B::_count = 0;

B b1;

//void func()
//{
//	B b;
//	b._count++;
//	B::_count++;
//}

class C
{
public:
	static C GetStackObj()
	{
		C newObj;
		return newObj;
	}

	static C* GetHeapObj()
	{
		C* pNewObj = new C;
		return pNewObj;
	}

private:
	C()
	{ }
};

//void func()
//{
//	C cStatck = C::GetStackObj();
//	C* cHeap = C::GetHeapObj();
//}

//int main()
//{
//	cout << __LINE__ << ' ' << B::GetCount() << endl; //1
//	B b2;
//	cout << __LINE__ << ' ' << B::GetCount() << endl; //2
//
//	//func();
//	//func();
//
//	cout << __LINE__ << ' ' << B::GetCount() << endl; //3
//	//func();
//	return 0;
//}

int main()
{
	C cStatck = C::GetStackObj();
	C* cHeap = C::GetHeapObj();
	return 0;
}