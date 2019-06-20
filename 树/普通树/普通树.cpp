// 普通树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<iomanip>
#include"parents_describing_tree.h"
#include"child_link_list_representation_tree.h"
#include"parents_child_link_tree.h"
#include"child_brother_tree.h"

using namespace std;

int main()
{
	////双亲表示法
	//ParentsDescribingTree<char> tree;
	//tree.AppendNode('a', -1);
	//tree.AppendNode('b', 0);
	//tree.AppendNode('c', 1);
	//tree.AppendNode('d', 1);
	//tree.Show();
	//cout << endl;

	//ParentDescrinbingTreeNode<char>node;
	//bool flag = tree.GetMaxIndex(node);
	//
	////保存根节点
	//ParentDescrinbingTreeNode<char>root;
	//cout << "node flag: " << flag << endl;
	//cout << "node data " << node.data_ << endl;
	//cout << "node parent:" << node.parent_ << endl;
	//bool root_flag = tree.Root(node, root);
	//if (root_flag)
	//	cout << setw(5) << root.data_ << setw(5) << root.parent_ << endl;

	//孩子表示法，孩子链表表示法
	//ChildLinkRepresentationTree<char>tree2;
	//tree2.AppendNode('a', -1);
	//tree2.AppendNode('b', 0);
	//tree2.AppendNode('c', 1);
	//tree2.AppendNode('d', 1);
	//tree2.Show();
	//cout << endl;

	//双亲孩子表示法
	//ParentsChildLinkTree<char>tree3;
	//tree3.AppendNode('a', -1);
	//tree3.AppendNode('b', 0);
	//tree3.AppendNode('c', 1);
	//tree3.AppendNode('d', 1);
	//tree3.Show();
	//cout << endl;

	//孩子兄弟表示法
	ChildBrotherTree<char>tree4;
	tree4.AppendNode('a', 'a');
	tree4.AppendNode('b', 'a');
	tree4.AppendNode('c', 'b');
	tree4.AppendNode('d', 'b');
	tree4.LevelOrder(tree4.GetRoot());
	cout << endl;
}
