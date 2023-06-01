#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

void test1()
{
	int a = 1;
	cout << &a << endl; //000000DB1EEFF764
	int b = 1;
	cout << &b << endl; //000000DB1EEFF784
}

class Solution {
public:
    int titleToNumber(string columnTitle)
    {
        int exponent = 0;
        int res = 0;
        string::reverse_iterator rIt = columnTitle.rbegin();
        while (rIt != columnTitle.rend())
        {
            char ch = *rIt;
            res += (int)pow(26, exponent++) * (ch - 'A' + 1);
            ++rIt;
        }
        return res;
    }
};

void test2()
{
    //cout << 701 / 26 << endl;
    //cout << 701 % 26 << endl;
    //int n = 52;
    //string res;
    //while (n > 26)
    //{
    //    char ch = n % 26 + 'A' - 1;
    //    res += ch;
    //    n /= 26;
    //}
    //char ch = n + 'A' - 1;
    //res += ch;

    //reverse(res.begin(), res.end());

    ////二进制转换
    //int n = 100;
    //string res;
    //while (n)
    //{
    //    char ch = n % 2 + '0';
    //    res += ch;
    //    n /= 2;
    //}
    //reverse(res.begin(), res.end());
    //cout << res << endl;
}

int main()
{
	//test1();
    test2();
	return 0;
}