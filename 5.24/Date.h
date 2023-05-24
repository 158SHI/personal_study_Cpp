#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class Date
{
  friend ostream& operator<<(ostream& cout, const Date& d);
  friend istream& operator>>(istream& cin, Date& d);

private:
  int _year;
  int _month;
  int _day;

public:
  Date(int year = 1918, int month = 7, int day = 7)
    :_year(year),
    _month(month),
    _day(day)
  {    
    if(!(month > 0 && month <= 12 && 
        day > 0 && day <= GetMonthDay(year, month)))
    {
      cout << "Error Date!" << endl;
      exit(-1);
    }
  }

  Date(const Date& d)
  {
    this->_year = d._year;
    this->_month = d._month;
    this->_day = d._day;
  }

  Date& operator=(const Date& d);

  static int GetMonthDay(int year, int month);

  int operator-(const Date& d) const;

  Date& operator+=(const int day);
  
  Date& operator-=(const int day);

  Date operator+(const int day) const;
  
  Date operator-(const int day) const;

  Date& operator++();

  Date operator++(int);

  Date& operator--();

  Date operator--(int);

  bool operator>(const Date& d);

  bool operator==(const Date& d);

  bool operator>=(const Date& d);

  bool operator<(const Date& d);

  bool operator<=(const Date& d);

  bool operator!=(const Date& d);
};
