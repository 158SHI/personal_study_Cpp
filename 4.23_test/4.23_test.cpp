#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

//#include <stdio.h>

using std::cin;
using std::cout;
using std::endl;



//class Date
//{
//private:
//	char c_;
//	int i_;
//	double d_;
//
//public:
//	void getChar(char c)
//	{
//		c_ = c;
//	}
//
//	void getInt(int i);
//};
//
//void Date::getInt(int i)
//{
//	i_ = i;
//}



int judgeSys(void)
{
	int a = 1;
	char* tmp = (char*)&a;
	return *tmp;
}

//class EmptyClass
//{
//public:
//	void Print(void)
//	{
//		cout << "hehe" << endl;
//	}
//};
//
//
//class GetNum
//{
//private:
//	char c_;
//	int num_;
//
//public:
//
//	void getNum(char c, int num)
//	{
//		c_ = c;
//		num_ = num;
//	}
//	void printNum(void)
//	{
//		cout << c_ << ' ' << num_ << endl;
//	}
//};

//int main()
//{
//	GetNum getM;
//	GetNum getN;
//	getM.getNum('b', 13); // getM.getNum(&getM, 'b', 13);
//	getN.getNum('a', 10); // getN.getNum(&getN, 'a', 10);
//	return 0;
//}
//
//class GetNum
//{
//private:
//	char c_;
//	int num_;
//
//public:
//
//	void getNum(const GetNum* const this, char c, int num)
//	{
//		this->c_ = c;
//		this->num_ = num;
//	}
//
//	void printNum(const GetNum* const this)
//	{
//		cout << this->c_ << ' ' << this->num_ << endl;
//	}
//};
//
//int main()
//{
//	GetNum getM;
//	GetNum getN;
//	getM.getNum(&getM, 'b', 13);
//	getN.getNum(&getN, 'a', 10);
//	return 0;
//}