#define _CRT_SECURE_NO_WARNINGS 1

#include "polynomial.h"

void test1()
{
	Polynomial poly1("x^5 - 5x^4 + 2x + 123");
	//poly1 = -poly1;
	//Polynomial poly1("123");
	Polynomial poly2("x^5 + 5x^4 + x^2 - x");
	//poly1 -= poly2;
	//Polynomial sumPoly = poly1 + poly2;
	//Polynomial subPoly = poly1 - poly2;
	poly1 += poly2;
}

void test4()
{
	Polynomial poly1;
	Polynomial poly2;
	cin >> poly1 >> poly2;
}

void test5()
{
	Polynomial poly1("-x^5 - 5x^4 + 2x + 123");
	cout << poly1 << endl;
}

//ʾ������
//ע��ʹ��ʱҪ�ϸ��ո�ʽ���ж���ʽ����
//��ָ������������룬ÿ����һ�ո����
void test()
{
	Polynomial poly1("x^5 - 5x^4 + 2x + 123");
	//Polynomial poly2("5x^5 + 5x^4 + x^2 - x");
	Polynomial poly2;
	cin >> poly2;

	cout << poly1 + poly2 << endl;
	cout << poly1 - poly2 << endl;

	poly1 -= poly2;

	cout << poly1 << endl;
	cout << poly2 << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	test();
	return 0;
}