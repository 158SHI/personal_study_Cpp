#include "Date.h"

void test1()
{
  Date d1(2023, 5, 24);
  cout << d1 << endl;

  Date d2;
  cin >> d2;
  cout << d2 << endl;
}

void test2()
{
  Date d1(2023, 5, 3);
  Date d2(d1);
  d1 += 28;
  cout << d1 << endl;
  d2 += 29;
  cout << d2 << endl;
}

void test3()
{
  Date d1(2023, 5, 24);
  d1 += 100;
  cout << d1 << endl;
}

void test4()
{
  Date d1(2023, 5, 24);
  Date d2(d1);
  d1 -= 100;
  cout << d1 << endl;
  
  d2 -= 1000;
  cout << d2 << endl;
}

void test5()
{
  Date d1(2023, 5, 24);
  Date d2 = d1;

 // cout << d1 << endl;
 // Date d3 = d1 - 100;
 // cout << d1 << endl;
 // cout << d3 << endl;

 // cout << "--------" << endl;

  cout << d2 << endl;
  Date d3 = d2 + 100;
  cout << d2 << endl;
  cout << d3 << endl;
}

void test6()
{
  Date d1(2023, 5, 24);
  Date d2(2022, 5, 24);
  cout << (d1 - d2) << endl;
}

int main()
{
  //test1();
  //test2();
  //test3();
  //test4();
  //test5();
  test6();
  return 0;
}
