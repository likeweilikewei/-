#include"head_link.h"
#include<iostream>

using namespace std;

#ifndef NULL
#define NULL 0
#endif

bool insert_list(Node* link, int pos,int value)
{
	if (pos < 0)
	{
		cout << "insert pos < 0,not normalize." << endl;
		return false;
	}
	
	//���û��ͷ����ֱ��ʧ��
	if (NULL == link)
	{
		cout << "insert link has no head node." << endl;
		return false;
	}
	
	int len = length_list(link);
	//���λ�ò������ڳ�����ʧ��
	if (pos > len)
	{
		cout << "pos > len of the link." << endl;
		return false;
	}

	int i = 0;
	Node* tmp_node=link;
	while (tmp_node != NULL && i < pos)
	{
		++i;
		tmp_node = tmp_node->next;
	}

	//�����;ʧ�����˳�
	if (tmp_node == NULL || i < pos)
	{
		cout << "insert link failed." << endl;
		return false;
	}

	Node* new_node = new Node;
	//��������ڴ�ʧ�����˳�
	if (NULL == new_node)
	{
		cout << "malloc mem failed." << endl;
		return false;
	}

	new_node->next = tmp_node->next;
	new_node->value = value;
	tmp_node->next = new_node;
	return true;
}
