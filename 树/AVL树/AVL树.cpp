// AVL树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"avl_tree.h"
#include<queue>
#include<stack>
#include"stack_by_array.h"
#include"queue_by_array.h"
#include"queue_by_list.h"
#include"stack_by_list.h"
#include"queue_by_link.h"
#include"stack_by_link.h"
#include"queue_by_two_stack.h"
#include"stack_by_two_queue.h"

//如果queue_by_array和queue_by_list定义相同函数则会出错，说类模板已经定义，应该使用不同函数名
//全局变量进行了初始化
//int a;

//void test()
//{
//	//函数内申请数组不会初始化
//	//函数内变量也不会初始化，输出会出错
//	int a;
//	//cout << a << endl;
//	int* s = new int[2];
//	for (int i = 0; i < 19; i++)
//		cout << s[i] << endl;
//}

int main()
{
	AvlTree<int> avl_tree;
	avl_tree.Construct();

	//得到根节点
	//AvlTreeNode<int>* root = avl_tree.get_root();
	//cout << root->data_ << endl;
	//递归前序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(),"preorder");
	//非递归前序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "preorder", 0);
	cout << endl;
	//递归中序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "inorder");
	//非递归中序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "inorder", 0);
	cout << endl;
	//递归后序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "postorder");
	//非递归后序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "postorder", 0);
	cout << endl;
	//层序遍历
	avl_tree.Traversal(avl_tree.get_root(), "levelorder");
	cout << endl << endl;

	//删除节点1
	int data_tmp = 1;
	cout << "delete node data of "<<data_tmp << endl;
	//原版删除节点
	//avl_tree.Delete(data_tmp);
	//新版递归删除节点
	avl_tree.Remove(data_tmp);

	//递归前序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "preorder");
	//非递归前序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "preorder", 0);
	cout << endl;
	//递归中序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "inorder");
	//非递归中序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "inorder", 0);
	cout << endl;
	//递归后序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "postorder");
	//非递归后序遍历二叉树
	avl_tree.Traversal(avl_tree.get_root(), "postorder", 0);
	cout << endl;
	//层序遍历
	avl_tree.Traversal(avl_tree.get_root(), "levelorder");


	////中序遍历中的前一个元素，先找左子树中最大元素，没有则查找值较小的父节点，查到根节点则没有，返回空指针
	//int data = 4;
	//AvlTreeNode<int>* node = avl_tree.PreviousNode(avl_tree.get_root(), data);
	//cout << data << " pre node data is " << node->data_ << endl;

	////中序遍历的后一个元素
	//node = avl_tree.ForwardNode(avl_tree.get_root(), data);
	//cout << data << " forward node data is " << node->data_ << endl;

	//测试
	//queue<int> queue;
	//queue.push(1);
	//queue.pop();

	//test();
	//main函数和普通函数情况一样
	//int a;
	//cout << a << endl;
	//int* s = new int[2];
	//for (int i = 0; i < 2; i++)
	//	cout << s[i] << endl;

	//测试数组堆栈
	//Stack<int> s;
	//s.push(1);
	//s.push(2);
	//int a = s.top();
	//cout << "a:" << a << endl;
	//s.pop();
	//a = s.top();
	//cout << "a:" << a << endl;
	//for (int i = 0; i < 200; i++)
	//{
	//	s.push(i);
	//	s.push(i);
	//	s.pop();
	//	cout << "top-------------------:" << (s.top()) << endl;
	//	cout << endl;
	//}

	//测试list堆栈
	//StackList<int> s;
	//s.push(1);
	//s.push(2);
	//int a = s.top();
	//cout << "a:" << a << endl;
	//s.pop();
	//a = s.top();
	//cout << "a:" << a << endl;
	//for (int i = 0; i < 200; i++)
	//{
	//	s.push(i);
	//	s.push(i);
	//	s.pop();
	//	cout << "top-------------------:" << (s.top()) << endl;
	//	cout << endl;
	//}

	////测试单边表堆栈
	//StackLink<int> s;
	//s.push(1);
	//s.push(2);
	//int a = s.top();
	//cout << "a:" << a << endl;
	//s.pop();
	//a = s.top();
	//cout << "a:" << a << endl;
	//for (int i = 0; i < 200; i++)
	//{
	//	s.push(i);
	//	s.push(i);
	//	s.pop();
	//	cout << "top-------------------:" << (s.top()) << endl;
	//	cout << endl;
	//}


	//测试队列构成的堆栈
	//StackQueue<int>stack_queue;
	//stack_queue.push(1);
	//stack_queue.push(2);
	//int a6 = stack_queue.top();
	//cout << "a:" << a6 << endl;
	//stack_queue.pop();
	//a6 = stack_queue.top();
	//cout << "a:" << a6 << endl;
	//for (int i = 0; i < 200; i++)
	//{
	//	stack_queue.push(i);
	//	stack_queue.push(i);
	//	stack_queue.pop();
	//	cout << "top-------------------:" << (stack_queue.top()) << endl;
	//	cout << endl;
	//}


	////测试标准堆栈
	//stack<int> s5;
	//s5.push(1);
	//s5.push(2);
	//int a5 = s5.top();
	//cout << "a:" << a5 << endl;
	//s5.pop();
	//a5 = s5.top();
	//cout << "a:" << a5 << endl;
	//for (int i = 0; i < 200; i++)
	//{
	//	s5.push(i);
	//	s5.push(i);
	//	s5.pop();
	//	cout << "top-------------------:" << (s5.top()) << endl;
	//	cout << endl;
	//}

	////测试堆栈构成的队列
	//QueueStack<int>queue_stack;
	//queue_stack.push(-1);
	//queue_stack.push(-2);
	//int a = queue_stack.back();
	//cout << "a:" << a << endl;
	////queue_stack.pop();
	//a = queue_stack.front();
	//cout << "a:" << a << endl;
	//cout << "back:" << (queue_stack.back()) << endl;
	//cout << "front:" << (queue_stack.front()) << endl;
	//cout << "---------------------------------" << endl;
	//for (int i = 0; i < 200; i++)
	//{
	//	queue_stack.push(i);
	//	queue_stack.push(i);
	//	queue_stack.pop();
	//	cout << "back:"<<(queue_stack.back()) << endl;
	//	cout << "front-------------------:" << (queue_stack.front()) << endl;
	//	cout << endl;
	//}
	//cout << (queue_stack.back()) << endl;

	//测试数组队列
	//Queue<int>s2;
	//s2.push(-1);
	//s2.push(-2);
	//int a = s2.back();
	//cout << "a:" << a << endl;
	////s2.pop();
	//a = s2.front();
	//cout << "a:" << a << endl;
	//cout << "back:" << (s2.back()) << endl;
	//cout << "front:" << (s2.front()) << endl;
	//cout << "---------------------------------" << endl;
	//for (int i = 0; i < 200; i++)
	//{
	//	s2.push(i);
	//	s2.push(i);
	//	s2.pop();
	//	cout << "back:"<<(s2.back()) << endl;
	//	cout << "front-------------------:" << (s2.front()) << endl;
	//	cout << endl;
	//}
	//cout << (s2.back()) << endl;

	////测试list队列
	//QueueList<int>s4;
	//s4.push(-1);
	//s4.push(-2);
	//int a = s4.back();
	//cout << "a:" << a << endl;
	////s4.pop();
	//a = s4.front();
	//cout << "a:" << a << endl;
	//cout << "back:" << (s4.back()) << endl;
	//cout << "front:" << (s4.front()) << endl;
	//cout << "---------------------------------" << endl;
	//for (int i = 0; i < 200; i++)
	//{
	//	s4.push(i);
	//	s4.push(i);
	//	s4.pop();
	//	cout << "back:" << (s4.back()) << endl;
	//	cout << "front-------------------:" << (s4.front()) << endl;
	//	cout << endl;
	//}
	//cout << (s4.back()) << endl;

	////测试单链表队列
	//QueueLink<int>s6;
	//s6.push(-1);
	//s6.push(-2);
	//int a = s6.back();
	//cout << "a:" << a << endl;
	////s6.pop();
	//a = s6.front();
	//cout << "a:" << a << endl;
	//cout << "back:" << (s6.back()) << endl;
	//cout << "front:" << (s6.front()) << endl;
	//cout << "---------------------------------" << endl;
	//for (int i = 0; i < 200; i++)
	//{
	//	s6.push(i);
	//	s6.push(i);
	//	s6.pop();
	//	cout << "back:" << (s6.back()) << endl;
	//	cout << "front-------------------:" << (s6.front()) << endl;
	//	cout << endl;
	//}
	//cout << (s6.back()) << endl;

	////测试标准队列
	//queue<int>s3;
	//s3.push(-1);
	//s3.push(-2);
	//int a2 = s3.back();
	//cout << "a:" << a2 << endl;
	////s3.pop();
	//a2 = s3.front();
	//cout << "a:" << a2 << endl;
	//cout << "back:" << (s3.back()) << endl;
	//cout << "front:" << (s3.front()) << endl;
	//cout << "---------------------------------" << endl;
	//for (int i = 0; i < 200; i++)
	//{
	//	s3.push(i);
	//	s3.push(i);
	//	s3.pop();
	//	cout << "back:" << (s3.back()) << endl;
	//	cout << "front-------------------:" << (s3.front()) << endl;
	//	cout << endl;
	//}
	//cout << (s3.back()) << endl;
	

	////负数取余还是负数，下面为-1
	//auto a1 = -8 % 7;
	//cout << a1 << endl;

	////数组初始化，列表初始化并指定了元素个数，不能多，可以少，但是不能用逗号略过
	//int array[3]= { 1,2};
	//cout << array[1] << endl;
	////数组访问-1索引非法
	//cout << array[-1] << endl;
	//int* a2 = new int[10]();  // 每个元素初始化为0,括号内不能写其他值，只能初始化为0
	//cout << a2[0] << endl;
	//const int n = 10;
	//int* a3 = new int[n];// 注意n必须为const,数组没有初始化
	//cout << a3[0] << endl;
	////正确的删除数组动作
	//delete []a3;

	//int value[9][9] = { {1,1},{2} }; //value[0][0,1]和value[1][0]的值初始化，其他初始化为0

	//cout << "-------------------" << endl;
	//int m = 10;
	//int(*value2)[n] = new int[m][n]();// n必须为常量，调用直观。未初始,加了括号就会初始化为0，否则未初始化
	//cout << value2[0][0] << endl;
	////删除单个地址空间
	//delete value2; 
	////这里会报错，删除数组空间
	//delete[]value2;

	exit(0);
}

