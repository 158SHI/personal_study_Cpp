#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream& cout, const Date& d);
	friend istream& operator>>(istream& cin, Date& d);

private:
	int _year;
	int _month;
	int _day;

public:
	Date(int year = 1500, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//ostream& operator<<(ostream& cout)
	//{
	//	cout << _year << "年" << _month << "月" << _day << "日";
	//	return cout;
	//}
};

ostream& operator<<(ostream& cout, const Date& d)
{
	cout << d._year << "年" << d._month << "月" << d._day << "日";
	return cout;
}

istream& operator>>(istream& cin, Date& d)
{
	cin >> d._year >> d._month >> d._day;
	return cin;
}

int main()
{
	Date d1;
	//cout << d1; //operator<<(cout, d)
	//d1 << cout; // d1.operator<<(&d1, cout)
	cin >> d1;
	cout << d1;
	return 0;
}