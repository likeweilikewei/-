#pragma once
#include"type.h"
#include<utility>

using namespace std;

struct Node {
	int value;
	Node* next;
};

//c++������һ���ṹ�����ֱ���ýṹ���������Ϳ��ԣ�c�б���Ҫ��struct����
//typedef struct NODE Node;

//����NodeΪȫ�ֱ����������������ļ���
extern Node* root;

//���쵥����,��ΪҪ�ں����ڲ��ı�ָ�뱾�������Ҫ��ָ���ָ�룬���ֻ�Ǹı����е�ֵ�Ļ�ֻ��ָ��Ϳ�����
void construct(Node**);

//�������������Ҫ�ı�ָ���ָ���������ָͨ��Ϳ�����
void show(Node*);

//����������Ĭ������
void sort(Node*, bool ascending=true);

//���㵥����ĸ���
int count(Node*);

//�ж�Ԫ���Ƿ����������У�����ھͷ���true
bool contain(Node*, int value);

//����Ԫ�ص���������
bool insert(Node**, int value);

//ɾ��Ԫ��,delete��c++�ؼ���
void deletes(Node**, int value);

typedef pair<bool, pair<Node*, Node*>> find_result;

//����Ԫ�أ�����pair,first:�Ƿ�ɹ���second.first:Ԫ�ص�ǰһ���ڵ㣬second��ǰ�ڵ㣬û���ҵ���first�����һ���ڵ㣬second��NULL������ҵ���һ���ڵ㣬��firstΪNULL
find_result find(Node*, int value);

//ɾ������
void free_link(Node**);

