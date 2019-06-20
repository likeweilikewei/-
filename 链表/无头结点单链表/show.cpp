#include "link.h"
#include <iostream>

using namespace std;

void show(Node* root)
/*
显示无头单链表信息
*/
{
	if (root == NULL)
	{
		cout << "no data in link." << endl;
	}
	else 
	{
		cout << "the link values is:" << endl;
		while (root != NULL)
		{
			cout << root->value << " ";
			root = root->next;
		}
		cout << endl;
	}

}
