#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class V
{
private:
	int* _a;
	int _sz;

public:
	V()
		:_a(new int[10]),
		_sz(0)
	{ }

	void push_back(const int& a)
	{
		assert(_sz < 10);
		_a[_sz++] = a; //¸³Öµ
	}

	int& operator[](size_t pos)
	{
		return _a[pos];
	}
};

void test1()
{
	int i = 10;

	vector<int> v;
	v.push_back(i);

	vector<int> v2;
	v2.push_back(i);
	cout << v2[0] << endl;

	v2[0]++;
	cout << v2[0] << endl;
}

void test2()
{
	V v;
	int i = 10;
	v.push_back(i);
}

class Solution {
public:
	string addBinary(string a, string b)
	{
		int end1 = a.size() - 1;
		int end2 = b.size() - 1;
		int carry = 0;
		string res;
		while (end1 >= 0 || end2 >= 0)
		{
			int val1 = end1 >= 0 ? a[end1] - '0' : 0;
			int val2 = end2 >= 0 ? b[end2] - '0' : 0;
			--end1; //0 -1
			--end2; //-1 -2
			int sum = (val1 + val2 + carry) % 2;
			carry = (val1 + val2 + carry) / 2;
			res.push_back(sum + '0');
		}
		if (carry == 1) {
			res.push_back('1');
		}
		reverse(res.begin(), res.end());
		return res;
	}
};

void test3()
{
	Solution().addBinary("11", "1");
}

int main()
{
	//test1();
	//test2();
	test3();
	return 0;
}