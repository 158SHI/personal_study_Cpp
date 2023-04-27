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
	int dayArr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

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

Date Date::operator+(int day)
{
	Date tmp = *this; //�˴����ÿ������캯��
	tmp += day;

	return tmp;
}

// ǰ��++
Date& Date::operator++()
{
	this->_day++;
	return *this;
}

// ����++
Date Date::operator++(int)
{
	Date tmp = *this;
	this->_day += 1;

	return tmp;
}

// >���������
bool Date::operator>(const Date& d)
{

}

// ==���������
bool Date::operator==(const Date& d)
{

}