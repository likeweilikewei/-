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

		//�������ʧ�ܻ�Ҫ�ͷ�֮ǰ������ڴ�
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

		//��һ���ڵ�
		if (NULL == current)
		{
			link = tmp;
			current = tmp;
			continue;
		}
		//���ǵ�һ���ڵ�ֱ��׷���ں���
		else
		{ 
			current->next = tmp;
			current = tmp;
		}
	}

	//��λ�����������
	cin.clear();
	while (cin.get() != '\n')
	{
		continue;
	}
	return link;
}