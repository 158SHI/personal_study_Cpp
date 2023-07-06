#define _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

using namespace std;

void test1()
{
	shr::string s("hello world");
	cout << s.c_str() << endl;
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << ' ';
	}
	cout << endl;

	shr::string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	const shr::string s2("hello shr");
	shr::string::const_iterator cit = s2.begin();
	while (cit != s2.end())
	{
		cout << *cit << ' ';
		++cit;
	}
	cout << endl;
}

void test2()
{
	shr::string s("hello world");
	//s.push_back('!');
	//s.push_back('!');
	//s.append(" hello!");
	//cout << s.c_str() << endl;

	s += '!';
	s += '!';
	s += " hello!";
	cout << s.c_str() << endl;
}

void test3()
{
	//shr::string s("hehe");
	//shr::string s2(s);
	////cout << s2.c_str() << endl;

	//s.insert(0, 3, '#');
	////cout << s.c_str() << endl;

	//s.insert(0, "xixi");
	//cout << s.c_str() << endl;

	shr::string s("hello world");
	//s.erase(7);
	//cout << s.c_str() << endl;
	//cout << s.find("hel");
	cout << s.substr(5).c_str() << endl;
}

void test4()
{
	shr::string s("hello world");
	//s.resize(20, '#');
	//s.clear();
	//cout << s.c_str() << endl;

	shr::string s2("hello C++");

	s.swap(s2);
	cout << s.c_str() << endl;

	cout << s.c_str() << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}