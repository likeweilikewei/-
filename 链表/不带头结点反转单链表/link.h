#pragma once
#pragma once
#include <iostream>
#include<stack>
#include<iomanip>
#include<vector>

using namespace std;

#ifndef NULL
#define NULL 0
#endif

struct Node {
	int value;
	Node* next;
	Node(){}
	Node(int values,Node*nexts=nullptr):value(values),next(nexts){}
};

typedef Node* NODE;
extern Node* root;
typedef NODE* NODE_LINK;

//构造单链表
NODE construct();

//遍历单链表
void traverse(NODE);

//反转单链表方法一，用堆栈或者数组存储所有节点，然后逆序重新构造,缺点是浪费空间
void reversal_1(NODE_LINK);

//反转单链表方法二，从第一个节点开始，用两个指向相邻节点的指针配合，使得后一个节点的next指针指向前一个，最后处理
//头结点，使得头结点next指向最后一个节点，第一个节点的next指向NULL
void reversal_2(NODE_LINK);

//反转单链表方法三，用一个指针总是指向第一个节点，不断将后一个节点插入到头结点的后面，直到最后一个节点
void reversal_3(NODE_LINK);

//反转单链表方法四，递归，每次都当除第一个节点之外的节点当成一个整体，让这个整体的next指向第一个节点，剩下的就是处理这个整体，终止条件是整体只有一个节点了
void reversal_4(NODE_LINK);
