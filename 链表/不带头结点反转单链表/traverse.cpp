#include"link.h"

void traverse(NODE link)
{
	if (NULL == link)
	{
		cout << "link is empty.";
		return;
	}
	while (link != NULL)
	{
		cout << setw(5) << link->value;
		link = link->next;
	}
	cout << endl;
}
