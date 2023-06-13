#pragma once

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Polynomial
{
	//�������ʽ
	friend ostream& operator<<(ostream& cout, const Polynomial& poly);
	//�������ʽ
	friend istream& operator>>(istream& cout, Polynomial& poly);

private:
	//�����ÿ���ڵ�洢��ÿ��ĳ�����x��ָ��
	list<pair<int, int>> _poly;

	/*
	ʹ������洢�����ʹ��˳���洢�ĺô���
	���ڴ󲿷���еĳ��ܶ���ʽ������Ĵ洢��ʽ������������
	���������ʽ�����ϡ���Ҹ���ָ�����ϴ�������洢���˷Ѵ����ռ䣬
	�ҽ��е�����������˷Ѵ���ʱ�������Ч����㡣
	ʹ������洢��ÿ���ڵ㶼�洢��һ����Ч������˿ռ��˷ѣ�
	����˶���ʽ�����Ч�ʡ�
	*/

	//��������ȡÿ���
	static int getLeftNum(string& poly, int pos);
	//��������ȡÿ��ָ��
	static int getRightNum(string& poly, int pos);

	void checkAndAdjust(); //�Զ���ʽ���м��͵���

public:
	Polynomial(string poly = ""); //����

	Polynomial& operator+=(Polynomial& poly);

	Polynomial& operator-=(Polynomial& poly);

	Polynomial operator+(Polynomial& poly) const;

	Polynomial operator-(Polynomial& poly) const;

	Polynomial operator-() const; //-��Ŀ���������
};