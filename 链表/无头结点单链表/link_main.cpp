#include <iostream>
#include"link.h"
#include <stdio.h>

using namespace std;

/*
���Ե�����ĸ��ֲ���
*/

Node* root = NULL;

int main()
{
	cout << "start construct link" << endl;
	construct(&root);

	//cout << root->value;
	show(root);
	cout << "start sort the link." << endl;
	sort(root, true);
	show(root);
	cout << "the link items number is:" << endl;
	cout << count(root) << endl;

	/*��ʼ���Ԫ���Ƿ��������У�������������
	�����֮ǰ�����뻺��
	c����
	while (getchar() != '\n')
		continue;	

	cin.clear()����������cin��״̬��ʾ���ģ�cin�ڽ��յ�����������ʱ�򣬻�����״̬λgood��
	���goodλ��Ϊ1����cin���������룬ֱ��������
	����´�����ǰ״̬λû�иı���ô��ʹ����˻�����������Ҳ�޷����롣�������������֮ǰ����Ҫcin.clear()��
	
	������״̬ΪgoodΪ1
	�����������sync()�����þ���������뻺�������ɹ�ʱ����0��ʧ��ʱbadbit����λ����������-1. 
	���⣬���ڰ��������������������sync()������ˢ�������������

	cin.get()�����ж���һ���ַ�������ĩβ�򷵻�EOF��Ҳ����-1,���¶��룬���������ķ���ֵ��int�ͣ�����ascii��
	cin.get(a)����һ��������
	��cin״̬Ϊ��Ϊ1��ʱ��cin.get()����-1��cin.get(a),int(a)�õ�-52
	�����cin����ʧ�ܺ�Ӧ��ʹ��cin.clear()�ָ�״̬λ�ſ��Զ������е�����

	int('2')==50
	�ַ�ת��Ϊintʱ����ascii��ת����
	*/
	/*auto a = cin.get()*/;
	//cin.clear();
	//char a;
	//cin.get(a);
	//cout <<"a:"<< int(a) << endl;
	//
	//while (a != '\n')
	//{
	//	cout <<"new a:"<< a << endl;

	//	auto b = cin.get();
	//	cout << "b:" << b << endl;

	//	cin.get(a);
	//	cout << "new a:" << a << endl;
	//	cout << "news a:" << int(a) << endl;
	//}
	//exit(99);

	//auto b = getchar();
	//while (b != '\n')
	//{
	//	cout <<"b:"<< b << endl;
	//	b = getchar();
	//	cout << "b:" << b << endl;
	//}
	//if (10 == '\n')
	//	cout << "yes";
	//cin.clear();

	int insert_value;
	cout << "please input a value to insert:" << endl;
	while (cin >> insert_value)
	{
		if (!contain(root, insert_value))
		{
			cout << "link not contain this value,can insert." << endl;
			break;
		}
		else
		{
			cout << "link hased this value,please input again:" << endl;
		}
	}

	//������cin״̬λgood��Ȼ��������뻺����
	cin.clear();
	while (cin.get() != '\n')
		continue;
	/*
	root�������ָ����ĵ�ֵַ��&root�����ָ��ĵ�ֵַ
	��˺���������ͬ��ǰ������ͬ
	*/
	//Node* root_tmp = root;
	//cout << root << endl;
	//cout << root_tmp << endl;
	//cout << &root << endl;
	//cout << &root_tmp << endl;

	if (insert(&root, insert_value))
	{
		cout << "insert to link successd.new link:" << endl;
		show(root);
		cout << "the link items number is:" << endl;
		cout << count(root) << endl;
	}
	else
	{
		cout << "insert to link failed." << endl;
	}
	cout << endl;

	//��ʼɾ��һ��Ԫ��
	int delete_value;
	cout << "please input a value to delete:" << endl;
	while (cin>>delete_value)
	{
		if (!contain(root, delete_value))
		{
			cout << "link do not has the value,please input again:" << endl;
		}
		else
		{
			cout << "link has the value,can delete." << endl;
			break;
		}
	}
	//���������
	cin.clear();
	while (cin.get() != '\n')
		continue;
	//ɾ�����Ԫ��
	deletes(&root, delete_value);
	cout << "delete after link is:" << endl;
	show(root);

	//ɾ����������
	free_link(&root);
	cout << "delete all value:" << endl;
	show(root);
}

