#include"head_link.h"
#include<iostream>

using namespace std;

#ifndef NULL
#define NULL 0
#endif

bool delete_list(Node* link, int pos, int*pData)
{
	cout << "start delete the link node in " << pos << endl;
	if (link == NULL)
	{
		cout << "delete the link has no head node,failed." << endl;
		return false;
	}

	//���ɾ���ڵ�λ��С�ڵ���0�������������Ҫ��
	if (pos <= 0)
	{
		cout << "pos <= 0,is not satisfy." << endl;
		return false;
	}

	int i = 0;
	Node* tmp_node = link;
	while (tmp_node != NULL && i < pos-1)
	{
		tmp_node = tmp_node->next;
		++i;
	}

	//��pos���ڳ���ʱ��ʧ��
	if (NULL == tmp_node->next||i<pos-1)
	{
		cout << "the link len<pos,delete failed." << endl;
		return false;
	}

	Node* delete_node;
	//����Ҫ��ʱ�����ɾ��
	if (i == pos-1 && tmp_node->next!=NULL)
	{
		delete_node = tmp_node->next;
		*pData = delete_node->value;
		tmp_node->next = tmp_node->next->next;
		delete delete_node;
		delete_node = 0;
		return true;
	}
	else
	{
		return false;
	}
}
