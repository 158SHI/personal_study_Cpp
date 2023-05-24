#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class A
{
private:
	static const int _i;
	static unordered_map<char, int> symbolToVal;
};

const int A::_i = 10;

unordered_map<char, int> A::symbolToVal =
{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

void test1()
{
    char c1 = 'a';
    char c2 = 'b';
    swap(c1, c2);
    cout << c1 << ' ' << c2 << endl;
}

void test2()
{
    string s1("xixi");
    string s2("haha");
    swap(s1, s2);
    //s1.swap(s2);
    cout << s1 << endl;
    cout << s2 << endl;
}

class CountClass
{
private:
    class Tmp
    {
    public:
        Tmp()
        {
            _ret += _i;
            ++_i;
        }
    };

private:
    static int _ret;
    static int _i;

public:
    int Sum(int n)
    {
        Tmp* pC = new Tmp[n];
        return _ret;
    }
};

int CountClass::_i = 1;
int CountClass::_ret = 0;

void test3()
{
    cout << CountClass().Sum(10) << endl;
}

int main()
{
	//test1();
    //test2();
    test3();
	return 0;
}