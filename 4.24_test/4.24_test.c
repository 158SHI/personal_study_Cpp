#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

 typedef struct TreeNode
 {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 }TreeNode;
 


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

typedef struct TreeNode* QueueDataType;

typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* front;
	QueueNode* back;
	int size;
}Queue;

void QueueInit(Queue* pQ)
{
	assert(pQ);
	pQ->front = NULL;
	pQ->back = NULL;
	pQ->size = 0;
}

void QueueDestory(Queue* pQ)
{
	assert(pQ);
	while (pQ->front)
	{
		QueueNode* nextNode = pQ->front->next;
		free(pQ->front);
		pQ->front = nextNode;
	}
	pQ->front = NULL;
	pQ->back = NULL;
	pQ->size = 0;
}

void QueuePush(Queue* pQ, QueueDataType x)
{
	assert(pQ);
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	assert(newNode);
	newNode->data = x;
	newNode->next = NULL;
	if (pQ->front == NULL)
	{
		assert(pQ->back == NULL);
		pQ->front = newNode;
		pQ->back = newNode;
	}
	else
	{
		pQ->back->next = newNode;
		pQ->back = newNode;
	}
	pQ->size++;
}

bool QueueEmpty(Queue* pQ)
{
	return pQ->size == 0;
}

void QueuePop(Queue* pQ)
{
	assert(pQ);
	assert(!QueueEmpty(pQ));
	QueueNode* nextNode = pQ->front->next;
	free(pQ->front);
	pQ->front = nextNode;
	if (pQ->front == NULL) {
		pQ->back = NULL;
	}
	pQ->size--;
}

int QueueSize(Queue* pQ)
{
	assert(pQ);
	return pQ->size;
}

QueueDataType QueueFront(Queue* pQ)
{
	assert(pQ);
	return pQ->front->data;
}

QueueDataType QueueBack(Queue* pQ)
{
	assert(pQ);
	return pQ->back->data;
}

/*-----------------------------------------------------*/

int* rightSideView(struct TreeNode* root, int* returnSize)
{
	int* retArr = (int*)malloc(sizeof(int) * 100);
	assert(retArr);

	Queue q;
	QueueInit(&q);
	if (root != NULL) {
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		int size = QueueSize(&q);

		for (int i = 0; i < size; i++)
		{
			struct TreeNode* front = QueueFront(&q);
			QueuePop(&q);

			if (front->left != NULL) {
				QueuePush(&q, front->left);
			}
			if (front->right != NULL) {
				QueuePush(&q, front->right);
			}

			if (i == size - 1) {
				retArr[(*returnSize)++] = front->val;
			}
		}
	}

	QueueDestory(&q);
	return retArr;
}

int main()
{
	TreeNode* n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->left = NULL;
	n1->right = NULL;
	n1->val = 1;

	TreeNode* n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n2->left = NULL;
	n2->right = NULL;
	n2->val = 2;

	TreeNode* n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n3->left = NULL;
	n3->right = NULL;
	n3->val = 3;

	TreeNode* n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n4->left = NULL;
	n4->right = NULL;
	n4->val = 4;

	TreeNode* n5 = (TreeNode*)malloc(sizeof(TreeNode));
	n5->left = NULL;
	n5->right = NULL;
	n5->val = 5;

	n1->left = n2;
	n1->right = n3;
	n2->right = n5;
	n3->right = n4;


	int retSz = 0;
	int* retA = rightSideView(n1, &retSz);
	for (int i = 0; i < retSz; i++)
	{
		printf("%d ", retA[i]);
	}
	printf("\n%d\n", retSz);

	free(retA);
	return 0;
}