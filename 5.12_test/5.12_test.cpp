#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <ostream>

using namespace std;

//int func2(A& a)
//{
//	//不含this指针
//}

//class C
//{
//	friend class B;
//	int a;
//	static int c;
//
//	void func()
//	{
//
//	}
//
//	class A
//	{
//	private:
//		int a;
//		static int b;
//
//	public:
//		void func(C& c)
//		{
//			c.func();
//			c;
//		}
//	};
//
//
//public:
//	int b;
//
//};
//
////void func()
////{
////	C c;
////	C::A a;
////	a.func(c);
////}
//
////class B
////{
////public:
////	void func1(C& c)
////	{
////		
////		c.func();
////		c.b++;
////
////
////	}
////
////
////};
//
//class Date
//{
//	friend ostream& operator<<(ostream& cout, const Date& d);
//
//private:
//	int _year;
//	int _month;
//	int _day;
//
//public:
//	Date(int year = 1840, int month = 6, int day = 1)
//		:_year(year),
//		_month(month),
//		_day(day)
//	{ }
//};
//
//ostream& operator<<(ostream& cout, const Date& d)
//{
//	cout << d._year << ' ' << d._month << ' ' << d._day;
//	return cout;
//}
//
//int main()
//{
//	Date d;
//	cout << d;
//	return 0;
//}

class D
{
private:
	int _n;

public:
	D(int n = 0)
		:_n(n) {
		cout << "D(int n)" << endl;
	}

	int GetN() {
		return _n;
	}

	~D() {
		cout << "~D()" << endl;
	}
};

int main()
{
	D d; //普通对象，生命周期在当前函数的局部域
	D(1); //匿名对象，生命周期在当前行
	cout << "-------" << endl;
	cout << D(2).GetN() << endl;
	cout << "-------" << endl;
	//D& rD = D(20); //错误
	const D& rD = D(20);
	D(3);
	cout << "-------" << endl;
	return 0;
}