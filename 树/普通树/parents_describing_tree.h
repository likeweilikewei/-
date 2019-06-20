#pragma once
#include<vector>
#include"parents_describing_tree_node.h"

using namespace std;

/*双亲节点树*/

template <typename T>
class ParentsDescribingTree
{
public:
	ParentsDescribingTree();
	~ParentsDescribingTree();
public:
	//查找节点所在树的根节点
	 bool Root(ParentDescrinbingTreeNode<T> node, ParentDescrinbingTreeNode<T>& result);
	 //添加节点
	 bool AppendNode(T data, int parent);
	 //输出所有节点
	 void Show();
	 //得到下标最大的 一棵树
	 bool GetMaxIndex(ParentDescrinbingTreeNode<T>& node);
private:
	//保存树节点的数组
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
	//下标超过容量
	if (node.parent_ >= tree_.size())
		return false;
	//得到根节点
	while (node.parent_ != -1)
		node = tree_[node.parent_];
	result = node;
	return true;
}

template<typename T>
inline bool ParentsDescribingTree<T>::AppendNode(T data, int parent)
/*添加节点*/
{
	//下标不合法,int 和unsigend int比较会将int向后者转化，-1会变大
	if (parent >= (int)tree_.size())
		return false;
	tree_.push_back(ParentDescrinbingTreeNode<T>(data, parent));
}

template<typename T>
inline void ParentsDescribingTree<T>::Show()
/*显示所有树节点*/
{
	int size = tree_.size();
	//cout << size;
	int i;
	for (i = 0; i < size; i++)
		cout << "data: " << tree_[i].data_ << " parent: " << tree_[i].parent_ << " i: " << i << endl;
}

template<typename T>
inline bool ParentsDescribingTree<T>::GetMaxIndex(ParentDescrinbingTreeNode<T>& node)
/*得到树的最后一个存储节点*/
{
	//树为空
	if (tree_.empty())
		return false;
	
	node = tree_.back();
	return true;
}

