#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

int main()
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

	return 0;
}