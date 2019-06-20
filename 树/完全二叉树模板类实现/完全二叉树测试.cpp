// 完全二叉树模板类实现.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
	//声明一个完全二叉树
	BinaryTree<char> binary_tree;
	//BinaryTree<int>* binary_tree=new BinaryTree<int>;
	//手动前序构建二叉树
	//binary_tree.set_root(binary_tree.ManualPreorderConstruct());
	//手动中序建立二叉树
	//binary_tree.set_root(binary_tree.ManualInorderConstruct());
	//手动后序建立二叉树
	//binary_tree.set_root(binary_tree.ManualPostorderConstruct());
	
	//层序自动建立二叉树
	binary_tree.LevelorderConstruct();

	//前序和中序建立二叉树
	//binary_tree.PreorderInorderConstruct();
	//中序和后序建立二叉树
	//binary_tree.InorderPostorderConstruct();

	//递归前序遍历二叉树
	//binary_tree.Traversal(binary_tree.get_root(),"preorder");

	//非递归前序遍历二叉树
	//binary_tree.Traversal(binary_tree.get_root(), "preorder", 0);
	//非递归中序遍历二叉树
	//binary_tree.Traversal(binary_tree.get_root(), "inorder", 0);
	//非递归后序遍历二叉树
	//binary_tree.Traversal(binary_tree.get_root(), "postorder", 0);
	//层序遍历二叉树
	binary_tree.Traversal(binary_tree.get_root(), "levelorder");

	//判断是否为空
	bool empty_flag = binary_tree.IsEmpty(binary_tree.get_root());
	cout << "the tree is empty?" << empty_flag << endl;

	//得到节点的父节点
	//BinaryTreeNode<char>* parent_node = binary_tree.Parent(binary_tree.get_root(), binary_tree.get_root()->left_child_->left_child_);
	//cout << "the node " << binary_tree.get_root()->left_child_->left_child_->data_ << " parent is:" << endl;
	//binary_tree.VistNode(parent_node);

	//得到节点数
	int size = binary_tree.Size(binary_tree.get_root());
	cout << "the tree size is:" << size << endl;

	//得到树的高度
	int height = binary_tree.HeightTree();
	cout << "the tree height is:" << height << endl;

	//得到树的深度
	int depth = binary_tree.DepthTree();
	cout << "the tree depth is:" << depth << endl;

	//得到节点深度
	int node_depth = binary_tree.Depth(binary_tree.get_root()->left_child_->left_child_);
	cout << "the tree node depth is:" << node_depth << endl;
}

