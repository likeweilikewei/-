// ��ȫ������ģ����ʵ��.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//


#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main()
{
	//����һ����ȫ������
	BinaryTree<char> binary_tree;
	//BinaryTree<int>* binary_tree=new BinaryTree<int>;
	//�ֶ�ǰ�򹹽�������
	//binary_tree.set_root(binary_tree.ManualPreorderConstruct());
	//�ֶ�������������
	//binary_tree.set_root(binary_tree.ManualInorderConstruct());
	//�ֶ�������������
	//binary_tree.set_root(binary_tree.ManualPostorderConstruct());
	
	//�����Զ�����������
	binary_tree.LevelorderConstruct();

	//ǰ���������������
	//binary_tree.PreorderInorderConstruct();
	//����ͺ�����������
	//binary_tree.InorderPostorderConstruct();

	//�ݹ�ǰ�����������
	//binary_tree.Traversal(binary_tree.get_root(),"preorder");

	//�ǵݹ�ǰ�����������
	//binary_tree.Traversal(binary_tree.get_root(), "preorder", 0);
	//�ǵݹ��������������
	//binary_tree.Traversal(binary_tree.get_root(), "inorder", 0);
	//�ǵݹ�������������
	//binary_tree.Traversal(binary_tree.get_root(), "postorder", 0);
	//�������������
	binary_tree.Traversal(binary_tree.get_root(), "levelorder");

	//�ж��Ƿ�Ϊ��
	bool empty_flag = binary_tree.IsEmpty(binary_tree.get_root());
	cout << "the tree is empty?" << empty_flag << endl;

	//�õ��ڵ�ĸ��ڵ�
	//BinaryTreeNode<char>* parent_node = binary_tree.Parent(binary_tree.get_root(), binary_tree.get_root()->left_child_->left_child_);
	//cout << "the node " << binary_tree.get_root()->left_child_->left_child_->data_ << " parent is:" << endl;
	//binary_tree.VistNode(parent_node);

	//�õ��ڵ���
	int size = binary_tree.Size(binary_tree.get_root());
	cout << "the tree size is:" << size << endl;

	//�õ����ĸ߶�
	int height = binary_tree.HeightTree();
	cout << "the tree height is:" << height << endl;

	//�õ��������
	int depth = binary_tree.DepthTree();
	cout << "the tree depth is:" << depth << endl;

	//�õ��ڵ����
	int node_depth = binary_tree.Depth(binary_tree.get_root()->left_child_->left_child_);
	cout << "the tree node depth is:" << node_depth << endl;
}

