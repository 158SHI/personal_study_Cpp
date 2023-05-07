#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Date
{
	friend ostream& operator<<(ostream& cout, const Date& d);

private:
	int _year;
	int _month;
	int _day;

public:

	Date* operator&()
	{
		return this;
	}

	const Date* operator&() const
	{
		return this;
	}

	Date(int year = 1500, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
};

ostream& operator<<(ostream& cout, const Date& d)
{
	cout << d._year << "Äê" << d._month << "ÔÂ" << d._day << "ÈÕ";
	return cout;
}

class Car
{
private:
	int _durability;
	int _speed;
	int _defence;

public:
	Car(int durbility = 100, int speed = 10, int defence = 10)
	{
		_durability = durbility;
		_speed = speed;
		_defence = defence;
	}

	void move()
	{

	}

	void SpeedUp()
	{

	}
};

int main()
{
	const Date d1(2023, 5, 7);
	//Date d1(2023, 5, 7);
	//const Date* pDate = &d1;
	cout << d1;
	return 0;
}