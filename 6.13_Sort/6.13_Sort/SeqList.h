#pragma once

#define MAX_SIZE 100000

// ˳���ṹ��
typedef struct
{
    int data[MAX_SIZE]; // ��������
    int length;         // ��ǰ����
} SeqList;

void initList(SeqList* list);
void insert(SeqList* list, int element);