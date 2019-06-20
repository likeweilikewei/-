#include"link.h"

NODE construct()
{
	NODE link = NULL;
	NODE tmp;
	NODE current = link;
	int value;

	cout << "please input link value,q to quit." << endl;
	
	while (cin >> value)
	{
		tmp = new(nothrow) Node;

		//如果申请失败还要释放之前申请的内存
		if (NULL == tmp)
		{
			NODE delete_tmp;
			while (NULL != link)
			{
				delete_tmp = link;
				link = link->next;
				delete delete_tmp;
				delete_tmp = NULL;
			}
			throw "new node failed.";
		}

		tmp->value = value;
		tmp->next = NULL;

		//第一个节点
		if (NULL == current)
		{
			link = tmp;
			current = tmp;
			continue;
		}
		//不是第一个节点直接追加在后面
		else
		{ 
			current->next = tmp;
			current = tmp;
		}
	}

	//置位和清除缓冲区
	cin.clear();
	while (cin.get() != '\n')
	{
		continue;
	}
	return link;
}