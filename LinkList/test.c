#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int type;
//������ṹ��
typedef struct Node {
	struct Node* _next;
	type _data;
}Node;
//��������ṹ��
typedef struct SingleList {
	Node* _head;
}SingleList;

//�����ʼ��
void SingleListInit(SingleList* sl) {
	sl->_head = NULL;
}
//����������
Node* creatNode(type data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	return node;
}

//β��
void SingleListPushBack(SingleList* sl, type data) {
	Node* node = creatNode(data);
	if (sl->_head == NULL)
		sl->_head = node;
	else {
		Node* last = sl->_head;
		while (last->_next) {
			last = last->_next;
		}
		last->_next = node;
	}
}

//ͷ��
void SingleListPushFront(SingleList* sl, type data) {
	Node* node = creatNode(data);
	if (sl->_head == NULL) {
		sl->_head = node;
	}
	else {
		node->_next = sl->_head;
		sl->_head = node;
	}
}

//βɾ
void SingleListPopBack(SingleList* sl) {
	if (sl->_head) {
		Node* prev = NULL;
		Node* tail = sl->_head;
		while (tail->_next) {
			prev = tail;
			tail = tail->_next;
		}
		if (tail == sl->_head) {
			sl->_head = NULL;
		}
		else {
			prev->_next = NULL;
		}
		free(tail);
	}
}

//ͷɾ
void SingleListPopFront(SingleList* sl) {
	if (sl->_head) {
		Node* cur = sl->_head;
		sl->_head = cur->_next;
		free(cur);
	}
}

//����λ�ú������
void SingleListInsertAfter(Node* pos, type data) {
	Node* newNode = creatNode(data);
	if (pos == NULL)
		return;
	newNode->_next = pos->_next;
	pos->_next = newNode;
}

//����λ�ú���ɾ��
void SingleListEraseAfter(Node* pos) {
	Node* next;
	if (pos == NULL)
		return;
	next = pos->_next;
	if (next) {
		pos->_next = next->_next;
		free(next);
	}
}

//��������
Node* find(SingleList* sl, type data) {
	Node* cur = sl->_head;
	while (cur) {
		if (cur->_data = data) {
			return cur;
		}
		cur->_next;
	}
	return NULL;
}

//���
void SingleListPrint(SingleList* sl) {
	Node* cur = sl->_head;
	while (cur) {
		printf("%d", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void singleListDestroy(SingleList* sl) {
	Node* cur = sl->_head;
	while (cur)
	{
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
}
//����ͷ��
void test1() {
	SingleList sl;
	SingleListInit(&sl);
	SingleListPushFront(&sl, 1);
	SingleListPrint(&sl);
	SingleListPushFront(&sl, 2);
	SingleListPrint(&sl);
	SingleListPushFront(&sl, 3);
	SingleListPrint(&sl);
	SingleListPushFront(&sl, 4);
	SingleListPrint(&sl);
}
//����β��
void test2() {
	SingleList sl;
	SingleListInit(&sl);
	SingleListPushBack(&sl, 1);
	SingleListPrint(&sl);
	SingleListPushBack(&sl, 2);
	SingleListPrint(&sl);
	SingleListPushBack(&sl, 3);
	SingleListPrint(&sl);
	SingleListPushBack(&sl, 4);
	SingleListPrint(&sl);
}
int main() {
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}