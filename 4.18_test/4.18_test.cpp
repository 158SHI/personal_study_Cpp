#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//namespace shr
//{
//	static int val = 10;
//}
//
//int& func()
//{
//	cout << shr::val << endl;
//	return shr::val;
//}
//
//int& func2()
//{
//	int val = 10;
//	//cout << val << endl;
//	return val;
//}
//
//int func3()
//{
//	static int val = 20;
//	return val;
//}
//
//int main()
//{
//	//int& ret = func();
//	//cout << ret << endl;
//	//ret++;
//	//cout << ret << endl;
//	//cout << shr::val << endl;
//	//int a = 10;
//	
//	//int& ra = a;
//	//int b = ra;
//	
//	const int& rret = func3();//权限平移
//
//	return 0;
//}


struct SeqList
{
	int data[100];
	int sz;
};

int& SeqAt(SeqList& s, int pos)
{
	return s.data[pos];
}

int Add(int x, int y)
{
	return x + y;
}


void Swap_p(int& x, int& y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void Swap_r(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int main()
{
	//int a = 10;
	//int b = 20;
	////cout << a << " " << b << endl;
	//Swap_p(a, b);
	//Swap_r(&a, &b);
	//cout << a << " " << b << endl;

	//SeqList sq;
	//
	//SeqAt(sq, 0) = 50;
	//cout << sq.data[0] << endl;

	//SeqAt(sq, 0) += 30;
	//cout << sq.data[0] << endl;

	//double d = 3.14;
	//int i = d;
	//int& i = d; // 权限放大

	//const int& i = d; //权限平移

	//int& rret = Add(12, 10);
	//const int& rret = Add(12, 10);

	int a = 20;
	int& b = a;
	int& c = b;
	int& d = a;
	cout << &a << endl;
	cout << &b << endl;
	cout << &c << endl;
	cout << &d << endl;

	return 0;
}