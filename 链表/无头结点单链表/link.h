#pragma once
#include"type.h"
#include<utility>

using namespace std;

struct Node {
	int value;
	Node* next;
};

//c++中声明一个结构体变量直接用结构体名声明就可以，c中必须要带struct声明
//typedef struct NODE Node;

//声明Node为全局变量，定义在其他文件中
extern Node* root;

//构造单链表,因为要在函数内部改变指针本身，因此需要用指针的指针，如果只是改变其中的值的话只用指针就可以了
void construct(Node**);

//输出单链表，不需要改变指针的指向，因此用普通指针就可以了
void show(Node*);

//单链表排序，默认升序
void sort(Node*, bool ascending=true);

//计算单链表的个数
int count(Node*);

//判断元素是否在在链表中，如果在就返回true
bool contain(Node*, int value);

//插入元素到单链表中
bool insert(Node**, int value);

//删除元素,delete是c++关键字
void deletes(Node**, int value);

typedef pair<bool, pair<Node*, Node*>> find_result;

//查找元素，返回pair,first:是否成功，second.first:元素的前一个节点，second当前节点，没有找到则first是最后一个节点，second是NULL，如果找到第一个节点，则first为NULL
find_result find(Node*, int value);

//删除链表
void free_link(Node**);

