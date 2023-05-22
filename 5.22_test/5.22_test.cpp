#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test1()
{
	int* pa = new int[10];
	delete[] pa;
}

template<typename T>
class A
{
private:

public:
	A()
	{

	}
};

void test2()
{
	string s1("hello world!!!!!!", 11);
	string s2(3, '!');
	s1 += s2;
	cout << s1 << endl;
}

void _test3(string& str, int a)
{
	if (a > 10) {
		_test3(str, a / 10);
	}
	str.push_back(a % 10 + '0');
}

void test3()
{
	int a = 3147;
	string str;
	_test3(str, a);
	cout << str << endl;
}

void test4()
{
	vector<string> v(3);
	v[0] = "xixi";
	v[1] = "ahah";

}

void test5()
{
	string s("xixixixi");
	for (int i = 0; s[i] != '\0'; i++)
	{
		cout << s[i] << endl;
	}
}

//class Solution {
//public:
//	string convert(string s, int numRows)
//	{
//		if (s.length() == numRows) {
//			return s;
//		}
//
//		vector<string> v(numRows);
//		int n = numRows - 1;
//		for (int i = 0; s[i] != '\0'; i++)
//		{
//			int curRow = 0;
//			if ((i / n) % 2 == 0) {
//				curRow = i % n;
//			}
//			else {
//				curRow = n - i % n;
//			}
//			(v[curRow]).push_back(s[i]);
//		}
//		string res;
//		for (int i = 0; i < numRows; i++) {
//			res += v[i];
//		}
//		return res;
//	}
//};

//void test6()
//{
//	string s("PAYPALISHIRING");
//	Solution sol;
//	sol.convert(s, 3);
//}

class Solution {
public:
	int myAtoi(string s)
	{
		if (s.empty()) return 0;
		int index = 0, n = s.size(), sign = 1, res = 0;
		// 处理前置空格
		while (index < n && s[index] == ' ') {
			++index;
		}
		// 处理符号
		if (index < n && (s[index] == '+' || s[index] == '-')) {
			sign = s[index++] == '+' ? 1 : -1;
		}
		// 处理数字
		while (index < n && isdigit(s[index])) {
			int digit = s[index] - '0';
			// 判断是否溢出
			if (res > (INT_MAX - digit) / 10) {
				return sign == 1 ? INT_MAX : INT_MIN;
			}
			res = res * 10 + digit;
			++index;
		}
		return res * sign;
	}
};

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	return 0;
}