#pragma once

#define MAX_SIZE 100000

// 顺序表结构体
typedef struct
{
    int data[MAX_SIZE]; // 数据数组
    int length;         // 当前长度
} SeqList;

void initList(SeqList* list);
void insert(SeqList* list, int element);