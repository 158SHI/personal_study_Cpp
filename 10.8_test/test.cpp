#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int add_f(int x, int y)
{
	return x + y;
}

struct add_o
{
	int operator()(int x, int y)
	{
		return x + y;
	}
};

void test0()
{
	auto f = [](int x, int y) { return x + y; };
	cout << typeid(f).name() << endl;
}

void test1()
{
	//包装器
	//函数名、函数对象、lambda表达式
	vector<function<int(int, int)>> funcPack = { add_f, add_o(), [](int x, int y) { return x + y; } };
	//cout << typeid(function<int(int, int)>).name() << endl;

	cout << funcPack[2](1, 4) << endl;
}

double profit(int pd1, int pd2, double rate)
{
	return (pd1 + pd2) * rate;
}

int sub(int x, int y)
{
	return x - y;
}

//bind包装器
void test2()
{
	//给某参数绑定一固定值
	function<double(int, int)> profit_1 = bind(profit, placeholders::_1, placeholders::_2, 0.8);
	cout << profit_1(5, 4) << endl;

	//非静态成员函数取地址时需要用 & 进行标识
	function<int(int, int)> func = bind(&add_o::operator(), add_o(), placeholders::_1, placeholders::_2);
	cout << func(3, 9) << endl;

	//指定参数传递
	func = bind(sub, placeholders::_2, placeholders::_1);
	cout << sub(5, 4) << endl;
	cout << func(5, 4) << endl;
}

//decltype
void test3()
{
	function<int(int, int)> func = add_f;
	decltype(func) func2 = sub;
	cout << func2(5, 9) << endl;
}

class demo
{
public:
	demo()
		:_p(new int[10])
	{ }

	demo(const demo& d)
	{
		cout << "demo(const demo& d), 深拷贝" << endl;
		_p = new int[10];
		for (int i = 0; i < 10; ++i) {
			_p[i] = d._p[i];
		}
	}

	demo(demo&& d)
	{
		cout << "demo(demo&& d), 移动拷贝" << endl;
		swap(_p, d._p);
	}

	~demo()
	{
		delete _p;
	}

private:
	int* _p;
};

demo ret()
{
	demo d;
	return d;
}

void test4()
{
	demo res = ret();
}

int main()
{
	//test0();
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}