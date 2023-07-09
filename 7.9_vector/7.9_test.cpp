#define _CRT_SECURE_NO_WARNINGS 1

#include <vector>
#include <iostream>
#include "vector.h"

using namespace std;

void test1()
{
	shr::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	for (auto e : v) {
		cout << e << ' ';
	}
	cout << endl;

	//v.pop_back();
	//v.pop_back();
	//v.pop_back();

	//for (auto e : v) {
	//	cout << e << ' ';
	//}

	//v.insert(v.begin(), 100);
	//v.insert(v.begin(), 200);

	//v.erase(v.end());
	//v.erase(v.end());
	v.erase(v.end());
	v.erase(v.begin());

	for (int i = 0; i < v.size(); ++i) {
		v[i]++;
	}
	for (auto e : v) {
		cout << e << ' ';
	}
	cout << endl;
}

void test2()
{
	shr::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (auto e : v) {
		cout << e << ' ';
	}
	cout << endl;

	shr::vector<int> v2(v);

	for (auto e : v2) {
		cout << e << ' ';
	}
	cout << endl;
}

int main()
{
	//test1();
	test2();
	return 0;
}