#include"head_link.h"
#include<iostream>

using namespace std;

#ifndef NULL
#define NULL 0
#endif


void bubble_sort(Node* link)
/*
√∞≈›≈≈–Ú
*/
{
	Node* tmp_node1;
	Node* tmp_node2;
	int tmp_value;

	cout << "start sort the list." << endl;
	if (NULL == link || NULL == link->next)
	{
		cout << "the list is empty,do not to sort." << endl;
		return;
	}
	for (tmp_node1 = link->next; tmp_node1->next != NULL; tmp_node1 = tmp_node1->next)
	{
		for (tmp_node2=tmp_node1->next;tmp_node2 !=NULL;tmp_node2=tmp_node2->next)
		{
			if (tmp_node1->value > tmp_node2->value)
			{
				tmp_value = tmp_node1->value;
				tmp_node1->value = tmp_node2->value;
				tmp_node2->value = tmp_value;
			}
		}
	}
	return;
}


void sort_list(Node* link)
/*
∂‘¡¥±Ì≈≈–Ú
*/
{
	bubble_sort(link);
}
