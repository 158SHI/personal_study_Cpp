#define _CRT_SECURE_NO_WARNINGS 1

#include "StuScoreMana.h"

void test()
{
	StuMana mana;
	//mana.Push();
	//mana.Push();
	//mana.Save();
	mana.Load();
	cout << mana << endl;
}

void test2()
{
	char arr[20] = "ab \x8a \n \\ 0192 \\";
	cout << strlen(arr);
}

int main()
{
	//test();
	test2();
	return 0;
}