#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

class A
{
private:
	int _i;

public:
	A(int i = 10)
		:_i(i)
	{
		cout << "A(int i)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
};

template<typename T> inline int min(T& a, T& b);

template<typename T> int min(T& a, T& b)
{
	return a < b ? a : b;
}

void test1()
{
	A* pA = (A*)operator new(sizeof(A) * 10); //����ռ�
	new(pA)A; //��ʾ���ù��캯����ʼ��һ������
	new(pA + 1)A[2]{ A(1), A(2) }; //��ʾ���ù��캯����ʼ���������

	pA->~A(); //��ʽ����
	(pA + 1)->~A();
	(pA + 2)->~A();

	operator delete(pA); //�ͷſռ�
}

void test2()
{
	string s("hello");
	cout << s << endl;
	s += " world";
	cout << s << endl;
	s.push_back('!');
	s.append("hehe");
	cout << s << endl;

	string s2("hehe", 1, 3);
	cout << s2 << endl;

	string s3(s, 0, 5);
	cout << s3 << endl;
}

int main()
{
	//test1();
	test2();
	return 0;
}