#include"head_link.h"

void traverse(NODE link)
{
	if (NULL == link)
	{
		cout << "link has no head node." << endl;
		return;
	}
	if (NULL == link->next)
	{
		cout << "link has no node." << endl;
		return;
	}
	while (link->next != NULL)
	{
		cout << link->next->value << " ";
		link = link->next;
	}
	cout << endl;
	return;
}
