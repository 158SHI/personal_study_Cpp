#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class A
{
public:
	int _a = 10;

	void  func()
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	int _a = 20;

public:
	//void func()
	//{
	//	cout << _a << endl;
	//	cout << A::_a << endl;
	//}
	void func(int a)
	{
		cout << "B" << endl;
	}
};

/*
虚函数的重写：
子类中含有与父类一样的虚函数，针对的是虚函数的函数名、参数和返回值
*/
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票，原价" << endl;
	};

	virtual ~Person()
	{
		cout << "~Person()" << endl;
	}
};

class Student : public Person
{
public:
	virtual void BuyTicket()
	{
		cout << "买票，半价" << endl;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
};

/*
* 多态有两个条件：
* 1.调用的函数必须是重写的虚函数
* 2.虚函数的调用必须由父类对象的引用或者指针进行
*/
void BuyTick(Person* p)
{
	p->BuyTicket();
}

void test1()
{
	Person* p = new Person;
	Student* s = new Student;
	BuyTick(p);
	BuyTick(s);
}

void test2()
{
	Person* p = new Person;
	delete p;

	// 普通调用看的是调用者(可能是对象、引用、指针)的类型
	// 多态调用看的是被引用/指向的对象
	// 希望对类对象的析构是一个多态调用
	p = new Student;
	delete p; //p->destructor() + operator delete(p)
}

int main()
{
	//B().A::func();
	//test1();
	test2();
	return 0;
}