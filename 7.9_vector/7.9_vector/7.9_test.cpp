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

void test3()
{
	shr::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	shr::vector<int> v2(v);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	v.swap(v2);

	for (auto e : v) {
		cout << e << ' ';
	}

	cout << endl;

	for (auto e : v2) {
		cout << e << ' ';
	}
}

void test4()
{
	shr::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	v.resize(10, 20);
	for (auto e : v) {
		cout << e << ' ';
	}
	cout << endl;

	v.resize(3);
	for (auto e : v) {
		cout << e << ' ';
	}
	cout << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}