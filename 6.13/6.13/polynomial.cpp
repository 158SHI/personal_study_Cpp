#define _CRT_SECURE_NO_WARNINGS 1

#include "polynomial.h"

int Polynomial::getLeftNum(string& poly, int pos)
{
	--pos;
	//������ϵ��Ϊ1��-1�����
	if (pos < 0 || (pos - 1 > 0 && poly[pos - 1] == '+')) {
		return 1;
	}
	if (poly[pos] == '-' || (poly[pos] == ' ' && poly[pos - 1] == '-')) {
		return -1;
	}

	//����һ�����
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
	//����ָ��Ϊ1�����
	if (pos == poly.size() || poly[pos] == ' ') {
		return 1;
	}
	//����һ�����
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
	//�����ַ�������ȡÿ��ĳ�����ָ��
	while ((pos = poly.find("x", pos)) != string::npos) {
		_poly.push_back({ getLeftNum(poly, pos), getRightNum(poly, ++pos) });
	}
	
	//�����������
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
	//����ʽ�鲢���
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
	//�鲢����ж���ʽ����
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
	//ȡÿ��ĳ���ϵ�����෴��
	for (auto& e : this->_poly) {
		ret._poly.push_back( {-e.first, e.second} );
	}
	return ret;
}

void Polynomial::checkAndAdjust()
{
	/*
	����ϵ��Ϊ0��ֱ��ɾ���ڵ�
	ָ����Ϊ1, ��������
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
	//��һ�δ�����Ҫ����ǰ�÷��ŵĴ�ӡ
	//firstTime������ʶ��һ�δ���
	bool firstTime = true; 
	//������ƴ�����ַ���formula�����
	for (auto& e : poly._poly)
	{
		//����ǰ�÷��Ŵ�ӡ
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
		//ָ����Ϊ0������ָ����ƴ��
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
	//����Ϊ��λ��ȡ����
	getline(cin, formula);
	Polynomial tmp(formula);
	poly = tmp;
	return cin;
}