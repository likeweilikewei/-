#pragma once
/*孩子兄弟表示法

这是一种常用的存储结构。其方法是这样的：在树中，每个结点除其信息域外，
再增加两个分别指向该结点的第一个孩子结点和下一个兄弟结点的指针。
在这种存储结构下，树中结点的存储表示可描述为：*/
#include<iostream>
#include<iomanip>
#include<queue>

using namespace std;

template <typename T>
class ChildBrotherNode
{
public:
	ChildBrotherNode();
	ChildBrotherNode(T data,ChildBrotherNode<T>*child=nullptr,ChildBrotherNode<T>*brother=nullptr):data_(data),child_(child),brother_(brother){}
	~ChildBrotherNode();
public:
	T data_;
	//第一个孩子
	ChildBrotherNode<T>* child_;
	//右兄弟
	ChildBrotherNode<T>* brother_;
};

template<typename T>
inline ChildBrotherNode<T>::ChildBrotherNode()
{
}

template<typename T>
inline ChildBrotherNode<T>::~ChildBrotherNode()
{
}


template <typename T>
class ChildBrotherTree
{
public:
	ChildBrotherTree(ChildBrotherNode<T>*root=nullptr):root_(root){}
	~ChildBrotherTree();
public:
	//得到根节点
	ChildBrotherNode<T>* GetRoot();
	//设置根节点
	void SetRoot(ChildBrotherNode<T>* root);
	//查找节点值是否存在
	ChildBrotherNode<T>* Search(ChildBrotherNode<T>*root, T data);
	//添加节点
	void AppendNode(T data, T parent_data);
	//层序遍历树
	void LevelOrder(ChildBrotherNode<T>* root);
private:
	ChildBrotherNode<T>* root_;
};

template<typename T>
inline ChildBrotherTree<T>::~ChildBrotherTree()
{
}

template<typename T>
inline ChildBrotherNode<T>* ChildBrotherTree<T>::GetRoot()
{
	return root_;
}

template<typename T>
inline void ChildBrotherTree<T>::SetRoot(ChildBrotherNode<T>* root)
{
	root_ = root;
}

template<typename T>
inline ChildBrotherNode<T>* ChildBrotherTree<T>::Search(ChildBrotherNode<T>* root, T data)
/*在树中查找节点值是否存在，不存在返回空指针，存在则返回相应节点*/
{
	if (root == nullptr)
		return nullptr;
	//保存返回结果
	ChildBrotherNode<T>* result = nullptr;
	//处理的当前节点
	ChildBrotherNode<T>* node = root;
	//保存树节点
	queue<ChildBrotherNode<T>*>nodes;
	//暂存树节点的兄弟节点
	ChildBrotherNode<T>* brother = nullptr;
	nodes.push(root);

	//层序遍历树查找节点
	while (!nodes.empty())
	{
		//遍历当前节点
		node = nodes.front();

		//如果是当前值则退出循环
		if (node->data_ == data)
			return node;

		//将该节点孩子节点入队列，并在这里将所有
		if (node->child_)
		{
			if (node->child_->data_ == data)
				return node->child_;
			nodes.push(node->child_);

			//只有在第一个孩子的地方才放入所有兄弟，这样就不会导致兄弟节点重复入队列
			brother = node->child_->brother_;
			while (brother)
			{
				if (brother->data_ == data)
					return brother;
				nodes.push(brother);
				brother = brother->brother_;
			}
		}

		//弹出节点
		nodes.pop();
	}
	return result;
}

template<typename T>
inline void ChildBrotherTree<T>::AppendNode(T data, T parent_data)
/*添加节点*/
{
	//插入节点
	ChildBrotherNode<T>* node = new ChildBrotherNode<T>(data);

	//如果树为空直接插入节点然后返回
	if (root_ == nullptr)
	{
		root_ = node;
		return;
	}

	//查找插入的节点，孩子兄弟表示法不方便插入重复节点值
	ChildBrotherNode<T>* result_data = Search(GetRoot(), data);
	ChildBrotherNode<T>* result_parent = Search(GetRoot(), parent_data);
	//暂时存储节点
	ChildBrotherNode<T>* brother = nullptr;

	//如果插入值存在不插入，或者父节点值不存在也不插入
	if (result_data != nullptr || result_parent == nullptr)
		return;

	//如果父节点孩子节点为空直接指向新节点
	if (result_parent->child_ == nullptr)
	{
		result_parent->child_ = node;
		return;
	}
	else
	{
		brother = result_parent->child_;
		while (brother->brother_ != nullptr)
			brother = brother->brother_;
		brother->brother_ = node;
	}
}

template<typename T>
inline void ChildBrotherTree<T>::LevelOrder(ChildBrotherNode<T>* root)
/*层序遍历树*/
{
	cout << "start level order the tree." << endl;
	if (root == nullptr)
		return;

	//保存节点
	queue<ChildBrotherNode<T>*>nodes;
	//暂存节点
	ChildBrotherNode<T>* node = root;
	nodes.push(node);
	//暂存孩子节点
	ChildBrotherNode<T>* child = nullptr;

	//遍历节点
	while (!nodes.empty())
	{
		node = nodes.front();

		child = node->child_;
		//如果该节点有孩子节点需要将所有孩子放入队列
		while (child)
		{
			nodes.push(child);
			child = child->brother_;
		}

		//输出节点
		cout << setw(5) << node->data_;
		//弹出节点
		nodes.pop();
	}
	cout << endl;
}
