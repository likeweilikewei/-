#include"head_link.h"
#include<iostream>

using namespace std;

void traverse_list(Node*link)
/*
遍历带头结点的单链表
*/
{
	cout << "start traverse the link." << endl;
	if (NULL == link||NULL==link->next)
	{
		cout << "link is NULL,do not have head node." << endl;
		return;
	}
	cout << "the link is:" << endl;
	while (NULL != link->next)
	{
		cout << link->next->value << " ";
		link = link->next;
	}
	cout << endl;
}
