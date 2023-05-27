#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

void test1()
{
	string s(to_string(1231));
	cout << s << endl;
}

int main()
{
	test1();
	return 0;
}