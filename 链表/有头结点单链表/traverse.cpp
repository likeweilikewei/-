#include"head_link.h"
#include<iostream>

using namespace std;

void traverse_list(Node*link)
/*
������ͷ���ĵ�����
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
