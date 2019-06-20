#pragma once

struct Node
{
	int value;
	Node* next;
};

extern Node* root;

//�����ͷ�ڵ㵥����
Node* construct();

//������ͷ���ĵ�����
void traverse_list(Node*);

//���ͷ��㵥����ĳ��ȣ�ͷ��㲻������
int length_list(Node*);

//�ж��Ƿ�Ϊ��
bool is_emptys(Node*);

//�������������
void sort_list(Node*);

//��ָ���ڼ����ڵ�������һ���½ڵ㣬ͷ���Ϊ��0���ڵ�
bool insert_list(Node*, int,int);

//ɾ��ָ��λ�õĽڵ㣬ͷ���Ϊ��0���ڵ㣬ͷ����޷�ɾ��
bool delete_list(Node*, int, int*);

//�������
void clear_list(Node*);
