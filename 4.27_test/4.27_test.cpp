#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

void test1(void)
{
	Date d1(2023, 4, 27);
	d1.ShowDate();

	Date d2(d1);
	d2.ShowDate();

	//d2 += 500; //d2.operator(100)
	//d2.ShowDate();

	//d2 = d1 + 100;
	//d2.ShowDate();

	d2 = d1++;
	d2.ShowDate();
	d1.ShowDate();
}

void test2(void)
{
	Date d1(2023, 4, 29);
	d1++;
	d1.ShowDate();
	d1++;
	d1.ShowDate();
	d1++;
	d1.ShowDate();
}

void test3(void)
{
	Date d1(2023, 4, 28);
	d1 -= 1000;
	d1.ShowDate();
}

int main()
{
	//test2();
	test3();
	return 0;
}