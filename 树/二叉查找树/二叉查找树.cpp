// 二叉查找树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"binary_search_tree.h"

int main()
{
	BinarySearchTree<int> binary_search_tree;
	//构建二叉查找树
	//binary_search_tree.Construct();
	//构建排序的二叉查找树,数据可以重复
	binary_search_tree.ConstructSortTree();

	//查看根节点
	cout << "the root data is:" << binary_search_tree.get_root()->data_ << endl;
	//递归前序遍历二叉查找树
	binary_search_tree.Traversal(binary_search_tree.get_root(), "preorder");
	//递归中序遍历二叉树
	binary_search_tree.Traversal(binary_search_tree.get_root(), "inorder");
	//递归后序遍历二叉查找树
	binary_search_tree.Traversal(binary_search_tree.get_root(), "postorder");
	//非递归前序遍历二叉查找树
	binary_search_tree.Traversal(binary_search_tree.get_root(), "preorder", 0);
	//非递归中序遍历二叉查找树
	binary_search_tree.Traversal(binary_search_tree.get_root(), "inorder", 0);
	//非递归后序遍历二叉查找树
	binary_search_tree.Traversal(binary_search_tree.get_root(), "postorder", 0);

	//判断数据是否在树中
	BinarySearchTreeNode<int>* searched_node;
	int search_data = 3;
	bool search_flag = binary_search_tree.Search(binary_search_tree.get_root(), search_data, searched_node);
	cout << search_data << " is " << (search_flag ? "in " : "not in ") << "tree." << endl;

	//删除节点
	/*
	//这里赋值得到也是一个复制指针，无法修改原始的树指针指向,错误做法
	//BinarySearchTreeNode<int>* node=binary_search_tree.get_root();
	//用解析指针可以得到原始的树的指针，正确的做法
	//BinarySearchTreeNode<int>** node_link = binary_search_tree.get_root_link();
	*/

	//binary_search_tree.Delete(*(binary_search_tree.get_root_link()),3);
	////递归前序遍历二叉查找树
	//binary_search_tree.Traversal(binary_search_tree.get_root(), "preorder");
	////递归中序遍历二叉树
	//binary_search_tree.Traversal(binary_search_tree.get_root(), "inorder");
	////判断数据是否在树中
	//search_flag = binary_search_tree.Search(binary_search_tree.get_root(), search_data, searched_node);
	//cout << search_data << " is " << (search_flag ? "in " : "not in ") << "tree." << endl;
}

