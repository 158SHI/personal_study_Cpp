#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

//void test1(void)
//{
//	Date d1(2023, 4, 27);
//	d1.ShowDate();
//
//	Date d2(d1);
//	d2.ShowDate();
//
//	//d2 += 500; //d2.operator(100)
//	//d2.ShowDate();
//
//	//d2 = d1 + 100;
//	//d2.ShowDate();
//
//	d2 = d1++;
//	d2.ShowDate();
//	d1.ShowDate();
//}
//
//void test2(void)
//{
//	Date d1(2023, 4, 29);
//	d1++;
//	d1.ShowDate();
//	d1++;
//	d1.ShowDate();
//	d1++;
//	d1.ShowDate();
//}
//
//void test3(void)
//{
//	Date d1(2023, 4, 28);
//	d1 -= 1000;
//	d1.ShowDate();
//}

void test4(void)
{
	Date d1(2023, 5, 6);
	Date d2 = d1;
	d2 -= -100;

	Date d3 = d1 + 100;

	cout << d2 << ' ' << d3 << endl;

	//Date d4(2023, 5, 38);
	//cin >> d4;
	//cout << d4 << endl;
	//d1.ShowDate();

	//cout << d1 - d2 << endl;
}

void test5(void)
{
	Date d1(2023, 5, 6);
	const Date d2(1949, 10, 1);
	
	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;
}

int main()
{
	//test2();
	//test3();
	//test4();
	test5();

	return 0;
}