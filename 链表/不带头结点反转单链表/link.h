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

//���쵥����
NODE construct();

//����������
void traverse(NODE);

//��ת��������һ���ö�ջ��������洢���нڵ㣬Ȼ���������¹���,ȱ�����˷ѿռ�
void reversal_1(NODE_LINK);

//��ת�������������ӵ�һ���ڵ㿪ʼ��������ָ�����ڽڵ��ָ����ϣ�ʹ�ú�һ���ڵ��nextָ��ָ��ǰһ���������
//ͷ��㣬ʹ��ͷ���nextָ�����һ���ڵ㣬��һ���ڵ��nextָ��NULL
void reversal_2(NODE_LINK);

//��ת��������������һ��ָ������ָ���һ���ڵ㣬���Ͻ���һ���ڵ���뵽ͷ���ĺ��棬ֱ�����һ���ڵ�
void reversal_3(NODE_LINK);

//��ת���������ģ��ݹ飬ÿ�ζ�������һ���ڵ�֮��Ľڵ㵱��һ�����壬����������nextָ���һ���ڵ㣬ʣ�µľ��Ǵ���������壬��ֹ����������ֻ��һ���ڵ���
void reversal_4(NODE_LINK);
