#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class E
{
private:
	int _i;

public:
	E(int i)
		:_i(i)
	{
		cout << "E(int i)" << endl;
	}

	E(const E& e)
		:_i(e._i)
	{
		cout << "E(const E& e)" << endl;
	}

	E& operator=(const E& e)
	{
		cout << "E& operator=(const E& e)" << endl;
		_i = e._i;
		return *this;
	}

	~E()
	{
		cout << "~E()" << endl;
	}
};

E func1()
{
	E e(35);
	return e;
}

void func2(E e)
{

}

int main()
{
	E e1 = 41; //同一行连续构造 + 拷贝构造 -> 构造
	//E& e2 = 44; // wrong
	const E& e2 = 44;

	E e3 = E(48); //同一行连续构造 + 拷贝构造 -> 构造 
	func2(E(52));//同一行连续构造 + 拷贝构造 -> 构造


	E e4 = func1(); //同一行连续拷贝构造 + 拷贝构造 -> 拷贝构造


	e1 = func1(); //同一行连续拷贝构造 + 赋值重载 -> 不优化
	e1 = E(62); //同一行连续拷贝构造 + 赋值重载 -> 不优化

	return 0;
}