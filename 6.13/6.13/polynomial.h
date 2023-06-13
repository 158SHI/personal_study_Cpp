#pragma once

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Polynomial
{
	//输出多项式
	friend ostream& operator<<(ostream& cout, const Polynomial& poly);
	//输入多项式
	friend istream& operator>>(istream& cout, Polynomial& poly);

private:
	//链表的每个节点存储：每项的常数和x的指数
	list<pair<int, int>> _poly;

	/*
	使用链表存储相对于使用顺序表存储的好处：
	对于大部分项都有的稠密多项式，数组的存储方式即可满足需求，
	但如果多项式的项较稀疏且各项指数相差较大，用数组存储会浪费大量空间，
	且进行的运算操作会浪费大量时间进行无效项计算。
	使用链表存储，每个节点都存储了一个有效项，减少了空间浪费，
	提高了多项式运算的效率。
	*/

	//解析、拿取每项常数
	static int getLeftNum(string& poly, int pos);
	//解析、拿取每项指数
	static int getRightNum(string& poly, int pos);

	void checkAndAdjust(); //对多项式进行检查和调整

public:
	Polynomial(string poly = ""); //构造

	Polynomial& operator+=(Polynomial& poly);

	Polynomial& operator-=(Polynomial& poly);

	Polynomial operator+(Polynomial& poly) const;

	Polynomial operator-(Polynomial& poly) const;

	Polynomial operator-() const; //-单目运算符重载
};