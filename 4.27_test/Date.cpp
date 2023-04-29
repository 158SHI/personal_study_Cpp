#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

//���캯��
Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

//�������캯��
Date::Date(const Date& d)
{
	this->_year = d._year;
	this->_month = d._month;
	this->_day = d._day;
}

//��ֵ��������غ���
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

//���������+=
Date& Date::operator+=(int day)
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

//+
Date Date::operator+(int day)
{
	Date tmp = *this; //�˴����ÿ������캯��
	tmp += day;

	return tmp;
}

// ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// ����++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;

	return tmp;
}

 //����-=����
Date& Date::operator-=(int day)
{
	if (day < this->_day) {
		this->_day -= day;
	}
	else if (day >= this->_day)
	{
		this->_day -= day;
		int curMonthDay = GetMonthDay(this->_year, this->_month);
		while (this->_day < 0)
		{
			this->_day += curMonthDay;
			this->_month -= 1;

			if (this->_month < 1)
			{
				this->_year -= 1;
				this->_month = 12;
			}

			curMonthDay = GetMonthDay(this->_year, this->_month);
		}
		this->_day += 1;
	}

	return *this;
}

// ����-����
Date Date::operator-(int day)
{
	Date tmp = *this;
	tmp -= day;
	return tmp;
}

// ����--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

// ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

//// ����-���� ��������
//int Date::operator-(const Date& d)
//{
//	//int monthLeft = this->_month;
//	//int monthRight = d._month;
//	//int dayLeft = this->_day;
//	//int dayRight = d._day;
//	//int sumLeft = 0;
//	//int sumRight = 0;
//	//for (int i = 1; i <= monthLeft; i++) {
//	//	sumLeft += GetMonthDay(this->_year, i);
//	//}
//	//sumLeft += dayLeft;
//
//	//for (int i = 1; i <= monthRight; i++) {
//	//	sumRight += GetMonthDay(d._year, i);
//	//}
//	//sumRight += dayRight;
//
//	//int subTmp = sumLeft - sumRight;
//	
//}

// >���������
bool Date::operator>(const Date& d)
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

// ==���������
bool Date::operator==(const Date& d)
{
	return this->_year == d._year &&
		this->_month == d._month &&
		this->_day == d._day;
}

bool Date::operator>=(const Date& d)
{
	return *this == d || *this > d;
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

// <=���������
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

// !=���������
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}