#include"head_link.h"
#include<iostream>

using namespace std;

#ifndef NULL
#define NULL 0
#endif // !NULL

void clear_list(Node* link)
/*
Çå¿ÕÁ´±í
*/
{
	cout << "start clear link." << endl;
	Node* p =link->next;
	Node* next_node = NULL;
	while (p != NULL)
	{
		next_node = p->next;
		delete p;
		p = next_node;
	}
	link->next = NULL;
}
