#pragma once

struct Node
{
	int value;
	Node* next;
};

extern Node* root;

//构造带头节点单链表
Node* construct();

//遍历带头结点的单链表
void traverse_list(Node*);

//求带头结点单链表的长度，头结点不计入内
int length_list(Node*);

//判断是否为空
bool is_emptys(Node*);

//对链表进行排序
void sort_list(Node*);

//在指定第几个节点后面插入一个新节点，头结点为第0个节点
bool insert_list(Node*, int,int);

//删除指定位置的节点，头结点为第0个节点，头结点无法删除
bool delete_list(Node*, int, int*);

//清空链表
void clear_list(Node*);
