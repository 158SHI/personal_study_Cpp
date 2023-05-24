#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
  static const int DayList[] = { 0, 31, 28, 31, 30, 31, 30, 31, 
  31, 30, 31, 30, 31 };
  if((month == 2) && 
      ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
  {
    return 29;
  }
  else {
    return DayList[month];
  }
}

Date& Date::operator=(const Date& d)
{
  _year = d._year;
  _month = d._month;
  _day = d._day;
  return *this;
}

bool Date::operator>(const Date& d)
{
  if(_year > d._year) {
    return true;    
  }
  else if(_year == d._year && _month > d._month) {
    return true;
  }
  else if(_year == d._year && _month == d._month &&
      _day > d._day) {
    return true;
  }
  else {
    return false;
  }
}

bool Date::operator==(const Date& d)
{
  return (_year == d._year && 
    _month == d._month &&
    _day == d._day);
}

bool Date::operator>=(const Date& d)
{
  return (*this == d || *this > d);
}

bool Date::operator<(const Date& d)
{
  return !(*this >= d);
}

bool Date::operator<=(const Date& d)
{
  return !(*this > d);
}

bool Date::operator!=(const Date& d)
{
  return !(*this == d);
}

int Date::operator-(const Date& d) const
{
  int count = 0;
  Date max = *this;
  Date min = d;
  if(max < min)
  {
    max = d;
    min = *this;
  }
  while(min != max)
  {
    ++min;
    ++count;
  }

  return count;
}

Date& Date::operator++()
{
  *this += 1;
  return *this;
}

Date Date::operator++(int)
{
  Date d = *this;
  *this += 1;
  return d;
}

Date& Date::operator--()
{
  *this -= 1;
  return *this;
}

Date Date::operator--(int)
{
  Date d = *this;
  *this -= 1;
  return d;
}

Date& Date::operator+=(const int day)
{
  _day += day;
  while(_day > GetMonthDay(_year, _month))
  {
    _day -= GetMonthDay(_year, _month);
    _month++;
    if(_month > 12)
    {
      _year++;
      _month = 1;
    }
  }
  return *this;
}
  
Date& Date::operator-=(const int day)
{
  _day -= day;
  while(_day <= 0)
  {
    --_month;
    if(_month == 0)
    {
      --_year;
      _month = 12;
    }
    _day += GetMonthDay(_year, _month);
  }
  return *this;
}

Date Date::operator+(const int day) const
{
  Date d = *this;
  d += day;
  return d;
}
  
Date Date::operator-(const int day) const
{
  Date d = *this;
  d -= day;
  return d;
}

ostream& operator<<(ostream& cout, const Date& d)
{
  cout << d._year << "_" << d._month << "_" <<
    d._day;
  return cout;
}

istream& operator>>(istream& cin, Date& d)
{
  int year, month, day;
  cin >> year >> month >> day;
  if(month > 0 && month <= 12 && 
      day > 0 && day <= Date::GetMonthDay(year, month))
  {
    d._year = year;
    d._month = month;
    d._day = day;
  }
  else
  {
    cout << "Error Date!" << endl;
    exit(-1);
  }
  return cin;
}
