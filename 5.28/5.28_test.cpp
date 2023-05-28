#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

#include <stdlib.h>
#include <assert.h>

struct ListNode
{
    int val;
    ListNode* next;
};

typedef struct ListNode ListNode;

ListNode* BuyNode(int val)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    assert(newNode);
    newNode->next = NULL;
    newNode->val = val;
    return newNode;
}

ListNode* CreatList(int n)
{
    int i = 1;
    ListNode* head = BuyNode(i++);
    ListNode* pTail = head;
    while (i <= n)
    {
        ListNode* newNode = BuyNode(i++);
        pTail->next = newNode;
        pTail = pTail->next;
    }
    pTail->next = head;
    return head;
}

int ysf(int n, int m)
{
    ListNode* phead = CreatList(n);
    ListNode* cur = phead;
    ListNode* prev = NULL;
    int i = 1;
    while (cur->next != cur)
    {
        if (i == m)
        {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
            i = 1;
        }
        else
        {
            prev = cur;
            cur = cur->next;
            i++;
        }
    }
    return cur->val;
}

void test1()
{
    ysf(5, 2);
}

int main()
{
	test1();
	return 0;
}