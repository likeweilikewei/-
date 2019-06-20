#pragma once
/*双亲表示法的树节点
由树的定义可以知道，树中的每个结点都有唯一的一个双亲结点，
根据这一特性，可用一组连续的存储空间（一维数组）存储树中的各个结点，
数组中的一个元素表示树中的一个结点，数组元素为结构体类型，
其中包括结点本身的信息以及结点的双亲结点在数组中的序号，树的这种存储方法称为双亲表示法。
其存储表示可描述为：如下
树的双亲表示法对于实现Parent（t，x）操作和Root（x）操作很方便，但若求某结点的孩子结点，
即实现Child（t，x，i）操作时，则需要查询整个数组。此外，
这种存储方式不能反映各兄弟结点之间的关系，所以实现RightSibling（t，x）操作也比较困难。
在实际中，如果需要实现这些操作，可在结点结构中增设存放第一个孩子的域和存放第一个右兄弟的域，
就能较方便地实现上述操作了。
*/

template <typename T>
class ParentDescrinbingTreeNode
{
public:
	//节点值
	T data_;
	//父节点在数组中的索引
	int parent_;
public:
	ParentDescrinbingTreeNode();
	~ParentDescrinbingTreeNode();
	ParentDescrinbingTreeNode(T data, int parent=-1);
};

template<typename T>
inline ParentDescrinbingTreeNode<T>::ParentDescrinbingTreeNode():parent_(-1)
{
}

template<typename T>
inline ParentDescrinbingTreeNode<T>::~ParentDescrinbingTreeNode()
{
}

template<typename T>
inline ParentDescrinbingTreeNode<T>::ParentDescrinbingTreeNode(T data, int parent)
/*初始化*/
{
	if (parent < -1)
		parent_ = -1;
	else
		parent_ = parent;
	data_ = data;
}
