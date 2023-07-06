#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include <iostream>

using namespace std;

// 初始化顺序表
void initList(SeqList* list)
{
    list->length = 0; // 将长度初始化为0
}

// 向顺序表中插入元素
void insert(SeqList* list, int element)
{
    if (list->length >= MAX_SIZE)
    {
        cout << "顺序表已满，无法插入新元素" << endl;
        return;
    }
    list->data[list->length] = element; // 将元素插入到顺序表末尾
    list->length++;                     // 长度加1
}
