#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

//构造函数
Date::Date(int year, int month, int day)
{
	if (month > 0 && month <= 12 &&
		day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "Illegal Date" << endl;
		assert(false);
	}
}

//拷贝构造函数
Date::Date(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
}

//赋值运算符重载函数
Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		this->_year = d._year;
		this->_month = d._month;
		this->_day = d._day;
	}
	
	return *this;
}

int Date::GetMonthDay(int year, int month)
{
	static int dayArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	if ((month == 2) && ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
		return 29;
	}

	return dayArr[month];
}

//运算符重载+=
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	else
	{
		this->_day += day;
		int curMonthDay = GetMonthDay(this->_year, this->_month);

		while (this->_day > curMonthDay)
		{
			this->_day -= curMonthDay;
			this->_month += 1;

			if (this->_month > 12)
			{
				this->_year += 1;
				this->_month = 1;
			}

			curMonthDay = GetMonthDay(this->_year, this->_month);
		}

		return *this;
	}
}

//+
Date Date::operator+(int day) const
{
	Date tmp = *this; //此处调用拷贝构造函数
	tmp += day;

	return tmp;
}

// 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// 后置++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;

	return tmp;
}

 //日期-=天数
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	else
	{
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}
}

// 日期-天数
Date Date::operator-(int day) const
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

// 后置--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

// 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

// 日期-日期 返回天数
int Date::operator-(const Date& d) const
{
	int n = 0;
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	while (max != min)
	{
		++min;
		++n;
	}

	return n * flag;
}

// >运算符重载
bool Date::operator>(const Date& d) const
{
	if (this->_year > d._year) {
		return true;
	}
	if (this->_year == d._year && this->_month > d._month) {
		return true;
	}
	if (this->_year == d._year && this->_month == d._month && this->_day > d._day) {
		return true;
	}

	return false;
}

// ==运算符重载
bool Date::operator==(const Date& d) const
{
	return this->_year == d._year &&
		this->_month == d._month &&
		this->_day == d._day;
}

bool Date::operator>=(const Date& d) const
{
	return *this == d || *this > d;
}

bool Date::operator<(const Date& d) const
{
	return !(*this >= d);
}

// <=运算符重载
bool Date::operator<=(const Date& d) const
{
	return !(*this > d);
}

// !=运算符重载
bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

ostream& operator<<(ostream& cout, const Date& d)
{
	cout << d._year << "年" << d._month << "月" << d._day << "日";
	return cout;
}

istream& operator>>(istream& cin, Date& d)
{
	int year, month, day;
	cin >> year >> month >> day;
	if (month > 0 && month <= 12 &&
		day > 0 && day <= d.GetMonthDay(year, month))
	{
		d._year = year;
		d._month = month;
		d._day = day;
		
		return cin;
	}
	else
	{
		cout << "Illegal Date" << endl;
		assert(false);
	}
}
