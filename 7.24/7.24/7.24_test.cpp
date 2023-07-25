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
�麯������д��
�����к����븸��һ�����麯������Ե����麯���ĺ������������ͷ���ֵ
*/
class Person
{
public:
	virtual void BuyTicket()
	{
		cout << "��Ʊ��ԭ��" << endl;
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
		cout << "��Ʊ�����" << endl;
	}

	~Student()
	{
		cout << "~Student()" << endl;
	}
};

/*
* ��̬������������
* 1.���õĺ�����������д���麯��
* 2.�麯���ĵ��ñ����ɸ����������û���ָ�����
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

	// ��ͨ���ÿ����ǵ�����(�����Ƕ������á�ָ��)������
	// ��̬���ÿ����Ǳ�����/ָ��Ķ���
	// ϣ����������������һ����̬����
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