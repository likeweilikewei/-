#include"link.h"
#include"type.h"
#include<iostream>

using namespace std;

#ifndef NULL
#define NULL 0
#endif

int judge_sort(Node* link)
/*
�жϵ������Ƿ�������õ�,����������򷵻�1����ȵ�Ϊ���򣬽��򷵻�-1��û�������򷵻�0
*/
{
	Node* tmp_node = link;
	while (tmp_node->next != NULL)
	{
		tmp_node = tmp_node->next;
	}
	//���������������ж�
	if (tmp_node->value >= link->value)
	{
		while (link->next != NULL)
		{
			if (link->value > link->next->value)
				return 0;
			link = link->next;
		}
		return 1;
	}
	else
	{
		while (link->next != NULL)
		{
			if (link->value < link->next->value)
				return 0;
			link = link->next;
		}
		return -1;
	}
}

bool insert_append(Node** head, int value)
/*
������򵥲��룬ֱ��׷���ں���
*/
{
	Node* link = *head;
	*head = link;
	while (link&&link->next != NULL)
		link = link->next;
	Node* tmp = new Node;
	if (tmp == NULL)
		return false;
	tmp->next = NULL;
	tmp->value = value;
	if (link == NULL)
		*head = tmp;
	else
		link->next = tmp;
	return true; 
}

bool insert_sort(Node** head, int value)
/*
�������ݵ�����õ������У��������������,���û������������ͨ��׷��
*/
{
	cout << "insert before link:" << endl;
	show(*head);
	Node* link = *head;
	*head = link;
	Node* tmp_node = new Node;
	if (tmp_node == NULL)
		return false;
	tmp_node->next = NULL;
	tmp_node->value = value;

	//�������Ϊ��ֱ�Ӳ���
	if (link == NULL)
	{
		*head = tmp_node;
		return true;
	}

	//ֻ��һ��Ԫ�ص������Ĭ��������,�����������ǽ�����ͬ��Ԫ��Ĭ�ϲ��뵽��һ��֮ǰ
	else if (link->next == NULL)
	{
		if (link->value >= value)
		{
			tmp_node->next = link;
			//�ı�linkָ��ĵط�Ҳ��Ҫ�ı�*head����ʹ��*headָ���µĵ�ַ
			*head = tmp_node;
		}
		else
			link->next = tmp_node;
		return true;
	}

	//����������Ԫ�ص����
	else
	{
		//�ж��������ǽ���,ͷ����Ԫ�������Ϊ�������,����ֵ��ͷ���ֵ֮ǰ��ֱ�Ӳ���ͷ���
		Node* link_tmp = link;
		while (link_tmp->next != NULL)
		{
			link_tmp = link_tmp->next;
		}

		//�ж��������ǽ�����������������ֱ����ӵ�����
		if (!judge_sort(link))
		{
		return insert_append(head, value);
		}

		//������ֵ���ڵ���ͷ���Ӳ��뵽ͷ���֮ǰ��������ֵС�ڵ���ͷ���Ҳ���뵽ͷ���֮ǰ
		if (link->value <= link_tmp->value&&value<=link->value||link->value>link_tmp->value&&value>=link->value)
		{
				tmp_node->next = link;
				//����Ҳ��һ������Ҫֱ�Ӹı�*head��ָ��
				*head = tmp_node;
				return true;
		}

		//���ҵ�ֵ���м�����������û�ҵ��������һ���ڵ㶼׷�ӵ����һ���ڵ���
		while (link->next != NULL)
		{
			int big_value = link->value > link->next->value ? link->value : link->next->value;
			int small_value = link->value < link->next->value ? link->value : link->next->value;
			if (big_value >= value && value >= small_value)
				break;
			//cout << "yes" << endl;
			//cout << big_value << value << small_value << endl;
			link = link->next;
		}
		//��������һ��ֱ��׷����ȥ,���ֲ��ı�linkָ��Ĳ��벻��Ҫ���¶�*head���иı䣬��Ϊ��ͷ*head�Ѿ�ָ�����������ͷ���
		if (link->next == NULL)
			link->next = tmp_node;
		//������뵽 �м�
		else
		{
			//cout << "now" << endl;
			tmp_node->next = link->next;
			link->next = tmp_node;
			//show(link);
		}
		return true;
	}
}

bool insert(Node** head, int value)
/*
���������
*/
{
	//bool flag = insert_append(head, value);
	bool flag=insert_sort(head,value);
	return flag;
}