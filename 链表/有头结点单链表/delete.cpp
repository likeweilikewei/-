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

	//如果删除节点位置小于等于0，则参数不符合要求
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

	//当pos大于长度时候失败
	if (NULL == tmp_node->next||i<pos-1)
	{
		cout << "the link len<pos,delete failed." << endl;
		return false;
	}

	Node* delete_node;
	//符合要求时候进行删除
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
