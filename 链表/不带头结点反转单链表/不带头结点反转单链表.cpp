// 不带头结点反转单链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include"link.h"

NODE root = NULL;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverse(ListNode* link, ListNode*& new_head)
	{
		//递归反转单链表，返回尾结点，new_head存放新头结点
		if (link == nullptr)
		{
			new_head = nullptr;
			return nullptr;
		}
		if (link->next == nullptr)
		{
			//找到了尾结点也就是新头结点
			new_head = link;
			return link;
		}
		ListNode* back_node = reverse(link->next, new_head);
		if (back_node == nullptr)
			return nullptr;
		back_node->next = link;
		link->next = nullptr;
		return link;
	}

	ListNode* reverseList(ListNode * head) {
		ListNode* new_head = nullptr;
		reverse(head, new_head);
		return new_head;
	}
};

int main()
{
	//根据用户输入得到链表
	//root = construct();

	//根据数组元素得到链表
	//vector<int>values{ 1,3,2 };
	//Node* current = nullptr;
	//Node* root = nullptr;
	//for (vector<int>::const_iterator iter = values.begin(); iter != values.end(); iter++)
	//{
	//	Node* tmp = new Node(*iter);
	//	if (current == nullptr)
	//	{
	//		root = tmp;
	//		current = tmp;
	//	}
	//	else
	//	{
	//		current->next = tmp;
	//		current = tmp;
	//	}
	//}

	//traverse(root);
	//reversal_1(&root);
	//traverse(root);
	//reversal_2(&root);
	//traverse(root);
	//reversal_3(&root);
	//traverse(root);
	//reversal_4(&root);
	//traverse(root);

	////用完释放链表
	//Node* delete_node = nullptr;
	//Node* tmp = root;
	//while (tmp != nullptr)
	//{
	//	delete_node = tmp;
	//	tmp = tmp->next;
	//	delete delete_node;
	//	delete_node = nullptr;
	//}

	//测试
	vector<int>values{ 1,3,2 };
	ListNode* current = nullptr;
	ListNode* root = nullptr;
	for (vector<int>::const_iterator iter = values.begin(); iter != values.end(); iter++)
	{
		ListNode* tmp = new ListNode(*iter);
		if (current == nullptr)
		{
			root = tmp;
			current = tmp;
		}
		else
		{
			current->next = tmp;
			current = tmp;
		}
	}
	Solution solution;
	ListNode* result = solution.reverseList(root);
	while (result != nullptr)
	{
		cout << result->val << endl;
		result = result->next;
	}
}

