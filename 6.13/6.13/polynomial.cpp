#define _CRT_SECURE_NO_WARNINGS 1

#include "polynomial.h"

int Polynomial::getLeftNum(string& poly, int pos)
{
	--pos;
	//处理常数系数为1或-1的情况
	if (pos < 0 || (pos - 1 > 0 && poly[pos - 1] == '+')) {
		return 1;
	}
	if (poly[pos] == '-' || (poly[pos] == ' ' && poly[pos - 1] == '-')) {
		return -1;
	}

	//处理一般情况
	int flag = 1;
	int res = 0;
	while (pos >= 0 && poly[pos] != '+' && poly[pos] != '-')
	{
		if (isdigit(poly[pos])) {
			res += (poly[pos] - '0') * flag;
			flag *= 10;
		}
		--pos;
	}
	if (pos < poly.size() && poly[pos] == '-') {
		res = -res;
	}
	return res;
}

int Polynomial::getRightNum(string& poly, int pos)
{
	//处理指数为1的情况
	if (pos == poly.size() || poly[pos] == ' ') {
		return 1;
	}
	//处理一般情况
	++pos;
	int res = 0;
	while (pos < poly.size() && poly[pos] != ' ')
	{
		res = res * 10 + (poly[pos] - '0');
		++pos;
	}
	return res;
}

Polynomial::Polynomial(string poly)
{
	if (poly == "") {
		return;
	}
	int pos = 0;
	//解析字符串，提取每项的常数和指数
	while ((pos = poly.find("x", pos)) != string::npos) {
		_poly.push_back({ getLeftNum(poly, pos), getRightNum(poly, ++pos) });
	}
	
	//常数项单独处理
	auto rit = poly.rbegin();
	bool flag = true;
	while (rit != poly.rend() && *rit != ' ')
	{
		if (!isdigit(*rit)) {
			flag = false;
			break;
		}
		rit++;
	}
	if (flag) {
		_poly.push_back({ getLeftNum(poly, poly.size()), 0 });
	}
}

Polynomial& Polynomial::operator+=(Polynomial& poly)
{
	auto itThis = this->_poly.begin();
	auto itPoly = poly._poly.begin();
	//多项式归并相加
	while (itThis != this->_poly.end() && itPoly != poly._poly.end())
	{
		if ((*itThis).second == (*itPoly).second)
		{
			(*itThis).first = (*itThis).first + (*itPoly).first;
			++itThis;
			++itPoly;
		}
		else if ((*itThis).second > (*itPoly).second)
		{
			++itThis;
		}
		else
		{
			this->_poly.insert(itThis, 
				{ (*itPoly).first, (*itPoly).second });
			++itPoly;
		}
	}
	while (itPoly != poly._poly.end())
	{
		this->_poly.push_back(*itPoly);
		++itPoly;
	}
	//归并后进行多项式调整
	this->checkAndAdjust();
	return *this;
}

Polynomial& Polynomial::operator-=(Polynomial& poly)
{
	Polynomial tmpPoly = -poly;
	(*this) += tmpPoly;
	return *this;
}

Polynomial Polynomial::operator+(Polynomial& poly) const
{
	Polynomial tmpPoly = *this;
	tmpPoly += poly;
	return tmpPoly;
}

Polynomial Polynomial::operator-(Polynomial& poly) const
{
	Polynomial tmpPoly = *this;
	tmpPoly -= poly;
	return tmpPoly;
}

Polynomial Polynomial::operator-() const
{
	Polynomial ret;
	//取每项的常数系数的相反数
	for (auto& e : this->_poly) {
		ret._poly.push_back( {-e.first, e.second} );
	}
	return ret;
}

void Polynomial::checkAndAdjust()
{
	/*
	常数系数为0，直接删除节点
	指数项为1, 不做处理
	*/
	auto it = this->_poly.begin();
	for (; it != this->_poly.end(); ++it)
	{
		if ((*it).first == 0) {
			auto preIt = --it;
			++it;
			_poly.erase(it);
			it = preIt;
		}
	}
}

ostream& operator<<(ostream& cout, const Polynomial& poly)
{
	string formula;
	//第一次处理不需要进行前置符号的打印
	//firstTime用来标识第一次处理
	bool firstTime = true; 
	//将各项拼接至字符串formula并输出
	for (auto& e : poly._poly)
	{
		//进行前置符号打印
		if (!firstTime && e.first > 0) {
			formula += '+';
		}
		firstTime = false;

		if (e.first != 1) {
			if (e.first == -1) {
				formula += '-';
			}
			else {
				formula += to_string(e.first);
			}
		}
		//指数不为0，进行指数的拼接
		if (e.second != 0)
		{
			formula += 'x';
			if (e.second != 1)
			{
				formula += '^';
				formula += to_string(e.second);
			}
		}
	}
	cout << formula;
	return cout;
}

istream& operator>>(istream& cin, Polynomial& poly)
{
	string formula;
	//以行为单位读取输入
	getline(cin, formula);
	Polynomial tmp(formula);
	poly = tmp;
	return cin;
}