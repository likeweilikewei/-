#include "link.h"
#include <iostream>

using namespace std;

void construct(Node** head)
/*
构造无头结点版本单链表
*/
{
	Node* current = *head;
	Node* tmp;
	int value;

	cout << "please input the first value(q to quit)" << endl;
	while (cin >> value)
	{
		tmp = new Node;
		tmp->value = value;
		tmp->next = NULL;
		//链接到表上，当前节点不空就连接到下一个节点上
		if (current != NULL)
			current->next = tmp;
		else
			//让实参指针重新指向链表的第一个节点，否则
			*head = tmp;
		//如果为空就直接赋值，如果不为空的情况也需要更新最新节点
		current = tmp;
		cout << "please input the next value(q to quit)" << endl;
	}

	//首先置cin状态位good，然后清空输入缓冲区
	cin.clear();
	while (cin.get() != '\n')
		continue;
}
