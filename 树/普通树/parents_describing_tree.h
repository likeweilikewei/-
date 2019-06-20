#pragma once
#include<vector>
#include"parents_describing_tree_node.h"

using namespace std;

/*˫�׽ڵ���*/

template <typename T>
class ParentsDescribingTree
{
public:
	ParentsDescribingTree();
	~ParentsDescribingTree();
public:
	//���ҽڵ��������ĸ��ڵ�
	 bool Root(ParentDescrinbingTreeNode<T> node, ParentDescrinbingTreeNode<T>& result);
	 //��ӽڵ�
	 bool AppendNode(T data, int parent);
	 //������нڵ�
	 void Show();
	 //�õ��±����� һ����
	 bool GetMaxIndex(ParentDescrinbingTreeNode<T>& node);
private:
	//�������ڵ������
	vector<ParentDescrinbingTreeNode<T>> tree_;
};

template<typename T>
inline ParentsDescribingTree<T>::ParentsDescribingTree()
{
}

template<typename T>
inline ParentsDescribingTree<T>::~ParentsDescribingTree()
{
}

template<typename T>
inline bool ParentsDescribingTree<T>::Root(ParentDescrinbingTreeNode<T> node, ParentDescrinbingTreeNode<T>& result)
{
	if (tree_.empty())
		return false;
	//�±곬������
	if (node.parent_ >= tree_.size())
		return false;
	//�õ����ڵ�
	while (node.parent_ != -1)
		node = tree_[node.parent_];
	result = node;
	return true;
}

template<typename T>
inline bool ParentsDescribingTree<T>::AppendNode(T data, int parent)
/*��ӽڵ�*/
{
	//�±겻�Ϸ�,int ��unsigend int�ȽϻὫint�����ת����-1����
	if (parent >= (int)tree_.size())
		return false;
	tree_.push_back(ParentDescrinbingTreeNode<T>(data, parent));
}

template<typename T>
inline void ParentsDescribingTree<T>::Show()
/*��ʾ�������ڵ�*/
{
	int size = tree_.size();
	//cout << size;
	int i;
	for (i = 0; i < size; i++)
		cout << "data: " << tree_[i].data_ << " parent: " << tree_[i].parent_ << " i: " << i << endl;
}

template<typename T>
inline bool ParentsDescribingTree<T>::GetMaxIndex(ParentDescrinbingTreeNode<T>& node)
/*�õ��������һ���洢�ڵ�*/
{
	//��Ϊ��
	if (tree_.empty())
		return false;
	
	node = tree_.back();
	return true;
}

