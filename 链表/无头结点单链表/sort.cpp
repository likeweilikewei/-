#include "link.h"

#ifndef NULL
#define NULL 0
#endif


void bubble_sort(Node* link, bool ascending = true)
/*
冒泡排序
*/
{
	if (link == NULL)
		return;
	for (Node * current = link; current->next != NULL; current = current->next)
	{
		for (Node* tmp = link; tmp->next != NULL; tmp = tmp->next)
		{
			if ((ascending&& tmp->value > tmp->next->value)||(!ascending&& tmp->value < tmp->next->value))
			{
					int tmp_value = tmp->value;
					tmp->value = tmp->next->value;
					tmp->next->value = tmp_value;
			}
		}
	}
}


void sort(Node* link, bool ascending)
/*
对单链表进行排序，默认升序,不用改变指针所指对象，只改变指针所指对象的值，只需要用指针就可以了
*/
{
	bubble_sort(link, ascending);
}
