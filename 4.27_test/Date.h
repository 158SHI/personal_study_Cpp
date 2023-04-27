#pragma once

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Date
{
private:
	int _year;
	int _month;
	int _day;

public:
	// ȫȱʡ�Ĺ��캯��
	Date(int year = 1, int month = 1, int day = 1);
	// �������캯��
	Date(const Date& d);
	// ��ֵ���������
	Date& operator=(const Date& d);

	// ��ȡĳ��ĳ�µ�����
	int GetMonthDay(int year, int month);
	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);
	// ǰ��++
	Date& operator++();
	// ����++
	Date operator++(int);
	// ����--
	Date operator--(int);
	// ǰ��--
	Date& operator--();
	// >���������
	bool operator>(const Date& d);
	// ==���������
	bool operator==(const Date& d);
	// >=���������
	bool operator >= (const Date& d);
	// <���������
	bool operator < (const Date& d);
	// <=���������
	bool operator <= (const Date& d);
	// !=���������
	bool operator != (const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);

	void ShowDate(void)
	{
		cout << _year << ' ' << _month << ' ' << _day << endl;
	}
};