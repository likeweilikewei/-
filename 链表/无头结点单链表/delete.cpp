#include"link.h"
#include<iostream>

using namespace std;

void deletes(Node** head, int value)
/*
ɾ��ָ����Ԫ��
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
		//����ǵ�һ���ڵ�,��Ҫ�ض���ָ��
		if (result.second.first == NULL)
		{
			*head = result.second.second->next;
			delete result.second.second;
		}
		//������ǵ�һ���ڵ㣬����Ҫ���¸ı�ָ��ָ��
		else
		{
			result.second.first->next = result.second.second->next;
			delete result.second.second;
		}
	}
}

void free_link(Node**prev)
/*
ɾ����������,������Ҫ�ı�ָ���ָ�������ָ���ָ��
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
