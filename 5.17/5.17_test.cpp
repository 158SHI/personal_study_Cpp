#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

template<typename T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T Add(const T& a, const T& b)
{
	return a + b;
}

template<typename T>
class Stack
{
private:
	T* _a;
	int _top;
	int _capacity;

public:
	Stack()
		:_a(new T[_capacity]),
		_top(0),
		_capacity(10)
	{ }

	Stack(const Stack& s)
	{

	}

	~Stack()
	{
		delete[] _a;
	}
};

void test1()
{
	Stack<int> s;

}

void test2()
{
	int a = 3;
	double b = 3.14;
	cout << Add<int>(a, b) << endl;
	cout << Add<double>(a, b) << endl;
}

int main()
{
	test1();
	test2();
	return 0;
}