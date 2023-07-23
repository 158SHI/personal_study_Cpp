#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Time
{
public:
	Time(int hour, int min, int sec)
		:_hour(hour),
		_min(min),
		_sec(sec)
	{ }

protected:
	int _hour;
	int _min;
	int _sec;
};

class Date : public Time
{
public:
	Date(int year, int month, int day)
		:Time(0, 0, 0), //需要在初始化列表使用父类的构造函数对父类成员进行初始化
		_year(year),
		_month(month),
		_day(day)
	{ }

	Date(const Date& date)
		:Time(date)
	{
		_year = date._year;
		_month = date._month;
		_day = date._day;
	}

protected:
	int _year;
	int _month;
	int _day;
};

class Calendar : public Date
{
public:
	Calendar(int zone)
		:Date(2023, 7, 23),
		_timeZone(zone)
	{ }

	void Print()
	{
		cout << _timeZone << ' ' << _year << ' ' <<
			_month << ' ' << _day << ' ' << _hour <<
			' ' << _min << ' ' << _sec << endl;
	}

protected:
	int _timeZone;
};

//class Cal
//{
//public:
//	Cal(int year, int month, int day)
//		:_date(year, month, day)
//	{ }
//
//	Date _date;
//};

class A
{
public:
	A()
		:_a(0),
		_aa(0),
		_aaa(0)
	{ }

	int _a;
	int _aa;
	int _aaa;
};

class B : virtual public A
{
public:
	B()
		:_b(0),
		_bb(0)
	{ }

	int _b;
	int _bb;
};

class C : virtual public A
{
public:
	C()
		:_c(0),
		_cc(0)
	{ }

	int _c;
	int _cc;
};

class D : public B, public C
{
public:
	D()
		:_d(0)
	{ }

	int _d;
};

void test1()
{
	D d;
	d._a = 20;
	d._aa = 40;
	d._aaa = 80;
	d._b = 2;
	d._bb = 4;
	d._c = 3;
	d._cc = 6;
	d._d = 4;

	//D d2;
	//d2._a = 20;
	//d2._aa = 40;
	//d2._aaa = 80;
	//d2._b = 2;
	//d2._bb = 4;
	//d2._c = 3;
	//d2._cc = 6;
	//d2._d = 4;
}

int main()
{
	//Cal c(2023, 7, 23);
	//cout << c._date._year << ' ' << c._date._month << ' ' << c._date._day << endl;
	//Calendar(8).Print();
	test1();
	return 0;
}