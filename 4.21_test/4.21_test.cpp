#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

void test(void)
{
	double arr[] = { 3.2,3.14,5.23,7.15,2.75,4.15,6.42,8.0 };
	for (auto e : arr) {
		cout << e << ' ';
	}
}

int main()
{
	cout << typeid(NULL).name() << endl;	//int
	cout << typeid(nullptr).name() << endl;	//std::nullptr_t
	
	cout << sizeof(nullptr) << endl;		//8(64 bit)
	cout << sizeof((void*)0) << endl;		//8(64 bit)
	cout << sizeof(NULL) << endl;			//4
	
	return 0;
}