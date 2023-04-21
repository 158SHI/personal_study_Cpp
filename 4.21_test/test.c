#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;

typedef struct ListNode
{
    LTDataType data;
    struct ListNode* prev;
    struct ListNode* next;
}ListNode;

//判空
bool ListEmpty(ListNode* pHead);

// 初始化
ListNode* LTInit(void);
// 销毁
void ListDestory(ListNode* pHead);

// 打印
void ListPrint(ListNode* pHead);
// 尾插
void ListPushBack(ListNode* pHead, LTDataType x);
// 尾删
void ListPopBack(ListNode* pHead);
// 头插
void ListPushFront(ListNode* pHead, LTDataType x);
// 头删
void ListPopFront(ListNode* pHead);

// 查找
ListNode* ListFind(ListNode* pHead, LTDataType x);
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);

ListNode* BuyNode(LTDataType x)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL)
    {
        perror("BuyNode::malloc");
        return NULL;
    }
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

bool ListEmpty(ListNode* pHead)
{
    assert(pHead);
    return pHead->next == pHead;
}

ListNode* LTInit(void)
{
    ListNode* newList = BuyNode(0);
    if (newList == NULL)
    {
        perror("LTInit::BuyNode");
        return NULL;
    }
    newList->data = 0;
    newList->prev = newList;
    newList->next = newList;
    return newList;
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListInsert(pHead, x);
}

void ListPopBack(ListNode* pHead)
{
    assert(pHead);
    if (ListEmpty(pHead)) {
        return;
    }
    ListErase(pHead->prev);
}

void ListPrint(ListNode* pHead)
{
    assert(pHead);
    ListNode* cur = pHead->next;
    while (cur != pHead)
    {
        printf("%d<->", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListInsert(pHead->next, x);
}

void ListPopFront(ListNode* pHead)
{
    assert(pHead);
    if (ListEmpty(pHead)) {
        return;
    }
    ListErase(pHead->next);
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
    assert(pHead);
    ListNode* cur = pHead->next;
    while (cur != pHead)
    {
        if (cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);
    ListNode* preNode = pos->prev;
    ListNode* newNode = BuyNode(x);
    preNode->next = newNode;
    newNode->prev = preNode;
    newNode->next = pos;
    pos->prev = newNode;
}

void ListErase(ListNode* pos)
{
    assert(pos);
    ListNode* prevNode = pos->prev;
    ListNode* nextNode = pos->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    free(pos);
}

void ListDestory(ListNode* pHead)
{
    assert(pHead);
    while (!ListEmpty(pHead))
    {
        ListPopFront(pHead);
    }
    free(pHead);
}

/*---------------------------------------------------*/

int GetNum(ListNode* head, int m)
{
    ListNode* begin = head->next;
    ListNode* end = head->next;
    int ret = 0;
    while (!ListEmpty(head))
    {
        ret = begin->data;
        int count = m;
        while (--count) {
            end = end->next;
            if (end->data == 0) {
                end = end->next;
            }
        }
        begin = end->next;
        if (begin->data == 0) {
            begin = begin->next;
        }
        ListErase(end);
        end = begin;
    }
    return ret;
}

int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d", &n, &m);
    ListNode* head = LTInit();
    for (int i = 1; i <= n; i++) {
        ListPushBack(head, i);
    }
    int res = GetNum(head, m);
    printf("%d\n", res);
    return 0;
}