#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include <iostream>

using namespace std;

// ��ʼ��˳���
void initList(SeqList* list)
{
    list->length = 0; // �����ȳ�ʼ��Ϊ0
}

// ��˳����в���Ԫ��
void insert(SeqList* list, int element)
{
    if (list->length >= MAX_SIZE)
    {
        cout << "˳����������޷�������Ԫ��" << endl;
        return;
    }
    list->data[list->length] = element; // ��Ԫ�ز��뵽˳���ĩβ
    list->length++;                     // ���ȼ�1
}
