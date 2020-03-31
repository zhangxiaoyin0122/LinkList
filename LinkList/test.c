#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int type;
//定义结点结构体
typedef struct Node {
	struct Node* _next;
	type _data;
}Node;
//定义链表结构体
typedef struct SingleList {
	Node* _head;
}SingleList;

//链表初始化
void SingleListInit(SingleList* sl) {
	sl->_head = NULL;
}
//创造结点数据
Node* creatNode(type data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	return node;
}

//尾插
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

//头插
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

//尾删
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

//头删
void SingleListPopFront(SingleList* sl) {
	if (sl->_head) {
		Node* cur = sl->_head;
		sl->_head = cur->_next;
		free(cur);
	}
}

//任意位置后面插入
void SingleListInsertAfter(Node* pos, type data) {
	Node* newNode = creatNode(data);
	if (pos == NULL)
		return;
	newNode->_next = pos->_next;
	pos->_next = newNode;
}

//任意位置后面删除
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

//查找数据
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

//输出
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
//测试头插
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
//测试尾插
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