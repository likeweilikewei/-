#include"head_link.h"
#include<iostream>

using namespace std;

Node* construct()
/*
�����ͷ�ڵ㵥����
*/
{
	Node* head = new Node;
	Node* link = head;
	if (NULL == head)
	{
		cout << "malloc Node failed." << endl;
		exit(-1);
	}
	link->next = NULL;
	 
	cout << "please input a value to construct(q to quit)" << endl;
	int value;
	while (cin >> value)
	{
		Node* tmp_node = new Node;
		if (NULL == tmp_node)
		{
			cout << "malloc Node failed." << endl;
			exit(-1);
		}
		tmp_node->next = NULL;
		tmp_node->value = value;
		link->next = tmp_node;
		link = tmp_node;
	}
	//���������
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return head;
}