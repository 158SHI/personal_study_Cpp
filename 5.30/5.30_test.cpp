#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

void test1()
{
	//basic_string<char> s;
	string s("hello");
	//s.reserve(100);
	//cout << s.capacity() << endl;

	//s.clear();
	//cout << s.size() << endl;
	//cout << s.capacity() << endl;

	s.assign("112\0 312");
}

void test2()
{
	string str("hello world hello linux");
	string res;
	for (auto ch : str)
	{
		if (ch == ' ') {
			res += "%20";
		}
		else {
			res += ch;
		}
	}
	cout << res << endl;
}

void test3()
{
	//ÍøÖ·½âÎö
	//string url("https://legacy.cplusplus.com/reference/string/");
	string url("https://legacy.cplusplus.com/reference/string/string/substr/");
	
	int pos1 = url.find("://");
	if (pos1 != string::npos) {
		string protocol = url.substr(0, pos1);
		cout << protocol << endl;
	}
	int pos2 = url.find('/', pos1 + 3);
	if (pos2 != string::npos)
	{
		string domain = url.substr(pos1 + 3, pos2 - (pos1 + 3));
		string uri = url.substr(pos2 + 1);
		cout << domain << endl;
		cout << uri << endl;
	}
}

void test4()
{
	//string s1("hello world");
	//string s2(s1);
	//if (s1.c_str() == s2.c_str()) {
	//	cout << "hehe" << endl;
	//}

	string s1("hello");
	s1.reserve(111);
	cout << s1.capacity() << endl;
	s1.reserve(7);
	cout << s1.capacity() << endl;
}

//class Solution {
//public:
//	string reverseStr(string s, int k)
//	{
//		int n = s.size();
//		string::iterator it = s.begin();
//		int i = 0;
//		for ( ; i < n; ++i)
//		{
//			if ((i + 1) % (2 * k) == 0)
//			{
//				reverse(it, it + k);
//				it += 2 * k;
//			}
//		}
//		if (s.end() - it >= k) {
//			reverse(it, it + k);
//		}
//		else {
//			reverse(it, s.end());
//		}
//		return s;
//	}
//};

class Solution {
public:
	string reverseWords(string s)
	{
		string::iterator it = s.begin();
		int pre_pos = 0;
		int pos = 0;
		while ((pos = s.find(' ', pre_pos)) != string::npos)
		{
			reverse(it, it + (pos - pre_pos));
			it += (pos - pre_pos + 1);
			pre_pos = ++pos;
		}
		reverse(it, s.end());
		return s;
	}
};

void test5()
{
	//Solution().reverseStr("abcdefg", 2);
	//Solution().reverseStr("abcd", 2);
}

void test6()
{
	Solution().reverseWords("Let's take LeetCode contest");
}

//void addStrings(string& num1, string& num2)
//{
//	int end1 = num1.size() - 1;
//	int end2 = num2.size() - 1;
//	int carry = 0;
//	string res;
//	while ((end1 >= 0 && num1[end1] != '-') || (end2 >= 0 && num1[end1] != '-'))
//	{
//		int val1 = end1 >= 0 ? (num1[end1] - '0') : 0;
//		int val2 = end2 >= 0 ? (num2[end2] - '0') : 0;
//		--end1;
//		--end2;
//		int sum = (val1 + val2 + carry) % 10;
//		carry = (val1 + val2 + carry) / 10;
//		res.push_back(sum + '0');
//	}
//	if (carry == 1) {
//		res.push_back('1');
//	}
//	reverse(res.begin(), res.end());
//	num1 = res;
//}

//void test7()
//{
//	string s1("123");
//	string s2("456");
//	addStrings(s1, s2);
//}

void test8()
{
	//string str("Hello Bit.");
	//str.reserve(111); //111
	//str.resize(5);
	//str.reserve(50);
	//cout << str.size() << ":" << str.capacity() << endl;

	string s("hello");
	s.reserve(111);
	cout << s.capacity() << endl;
	s.reserve(15);
	cout << s.capacity() << endl;
}

void test9()
{

}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	return 0;
}