#include"link.h"

#ifndef NULL
#define NULL 0
#endif

int count(Node* link)
/*
计算单链表的元素个数
*/
{
	int item_count = 0;
	while (link != NULL)
	{
		item_count += 1;
		link = link->next;
	}
	return item_count;
}
