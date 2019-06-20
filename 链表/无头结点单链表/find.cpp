#include"link.h"

//using namespace std;

find_result find(Node* link, int value)
/*
查找元素，返回pair,first:是否找到，second:pair,first:前一个节点，second:当前节点
*/
{
	find_result result(false, pair<Node*, Node*>(NULL, NULL));
	if (link == NULL)
		return result;

	//当时第一个节点时候
	if (link->value == value)
	{
		result.first = true;
		result.second.second = link;
		return result;
	}

	while (link->next!=NULL)
	{
		if (link->next->value == value)
		{
			break;
		}
		link = link->next;
	}
	//当没有找到的时候
	if (link->next == NULL)
	{
		return result;
	}
	//找到并且不是第一个节点的时候
	else
	{
			result.first = true;
			result.second.first = link;
			result.second.second = link->next;
			return result;
	}
}