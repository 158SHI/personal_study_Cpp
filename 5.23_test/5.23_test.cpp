#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <utility>

using namespace std;

void test1()
{
	string s1("111111111111");
	cout << s1 << endl;
	s1.clear();
	cout << s1 << endl;
}

void test2()
{
	string s1("123456");
	string::iterator strIt = s1.begin();
	string::reverse_iterator strRit = s1.rbegin();
	while (strIt != s1.end())
	{
		cout << *strIt << ' ';
		++strIt;
	}
	cout << endl;

	while (strRit != s1.rend())
	{
		cout << *strRit << ' ';
		++strRit;
	}
	cout << endl;
}

//class Solution {
//public:
//    int myAtoi(string s)
//    {
//        if (s.empty()) return 0;
//        int index = 0, n = s.size(), sign = 1, res = 0;
//        // 处理前置空格
//        while (index < n && s[index] == ' ') {
//            ++index;
//        }
//        // 处理符号
//        if (index < n && (s[index] == '+' || s[index] == '-')) {
//            sign = s[index++] == '+' ? 1 : -1;
//        }
//        // 处理数字
//        while (index < n && isdigit(s[index])) {
//            int digit = s[index] - '0';
//            // 判断是否溢出
//            if (res > (INT_MAX - digit) / 10) {
//                return sign == 1 ? INT_MAX : INT_MIN;
//            }
//            res = res * 10 + digit;
//            ++index;
//        }
//        return res * sign;
//    }
//};

//class A
//{
//private:
//	static const int _a;
//
//};
//
//const int A::_a = 0;
//
//const pair<int, int> p[] =
//{
//	{1,2},
//	{1,3},
//};
//
//void test3()
//{
//	int a[] = { 1, 2, 3 };
//	p->first;
//}

class Solution
{
private:
    static const pair<int, string> valueSymbols[];

public:
    string intToRoman(int num);
};

const pair<int, string> Solution::valueSymbols[] =
{
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

string Solution::intToRoman(int num)
{
    string res;
    for (const auto& e : valueSymbols)
    {
        const int n = e.first;
        const string symbol = e.second;
        while (num >= n)
        {
            num -= n;
            res += symbol;
        }
        if (num == 0) {
            break;
        }
    }
    return res;
}

void test4()
{
    int* pa = new int[10] { 0 };
    int arr[] = { 1,2,3 };//可以针对数组使用范围for，因为迭代范围是明确的

    /*不能针对动态开辟的数组使用range for，因为所拥有的只是指向第一个元素的指针*/
    //for (int e : pa) 
    //{
    //    cout << e << ' ';
    //}
}

inline int sum(int x, int y)
{
    return x + y;
}

inline double sum(double x, double y)
{
    return x + y;
}

void test5()
{
    cout << sum(1, 2) << endl;
    cout << sum(3.14, 5.12) << endl;
}

class A
{
private:
    int _i;

public:
    A(int i = 10)
        :_i(i)
    {
        cout << "A()" << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }
};

class B
{
private:
    int _i;

public:
    B(int i = 10)
        :_i(i)
    {
        cout << "B()" << endl;
    }

    B(const B& b)
    {
        cout << "B(const B& b)" << endl;
    }

    ~B()
    {
        cout << "~B()" << endl;
    }
};

class C
{
private:
    int _i;
    B _b;

public:
    C(int i = 10)
        :_i(i),
        _b()
    {
        cout << "C()" << endl;
    }

    ~C()
    {
        cout << "~C()" << endl;
    }
};
void test6()
{
    //A* pA = new A;
    //delete pA;
    //B b;

    //static C c;

    C c1;
    C c2(c1);
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