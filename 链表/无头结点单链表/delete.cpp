#include"link.h"
#include<iostream>

using namespace std;

void deletes(Node** head, int value)
/*
删除指定的元素
*/
{
	Node* link = *head;
	//*head = link;
	find_result result = find(*head, value);
	if (!result.first)
		cout << "link do not has the value,did not need to delete." << endl;
	else
	{
		cout << "start delete the value:" << value << endl;
		//如果是第一个节点,需要重定向指针
		if (result.second.first == NULL)
		{
			*head = result.second.second->next;
			delete result.second.second;
		}
		//如果不是第一个节点，不需要重新改变指针指向
		else
		{
			result.second.first->next = result.second.second->next;
			delete result.second.second;
		}
	}
}

void free_link(Node**prev)
/*
删除整个链表,由于需要改变指针的指向，因此用指针的指针
*/
{
	Node* tmp;
	while (*prev != NULL)
	{
		tmp = (*prev)->next;
		delete* prev;
		*prev = tmp;
	}
}
