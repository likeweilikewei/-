#include "link.h"

#ifndef NULL
#define NULL 0
#endif

bool contain(Node* link,int value)
/*
�ж�Ԫ���Ƿ���������
*/
{
	bool flag = false;
	while (link!=NULL)
	{
		if (link->value == value)
		{
			flag = true;
			break;
		}
		link = link->next;
	}
	return flag;
}