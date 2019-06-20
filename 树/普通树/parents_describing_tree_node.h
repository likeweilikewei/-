#pragma once
/*˫�ױ�ʾ�������ڵ�
�����Ķ������֪�������е�ÿ����㶼��Ψһ��һ��˫�׽�㣬
������һ���ԣ�����һ�������Ĵ洢�ռ䣨һά���飩�洢���еĸ�����㣬
�����е�һ��Ԫ�ر�ʾ���е�һ����㣬����Ԫ��Ϊ�ṹ�����ͣ�
���а�����㱾�����Ϣ�Լ�����˫�׽���������е���ţ��������ִ洢������Ϊ˫�ױ�ʾ����
��洢��ʾ������Ϊ������
����˫�ױ�ʾ������ʵ��Parent��t��x��������Root��x�������ܷ��㣬������ĳ���ĺ��ӽ�㣬
��ʵ��Child��t��x��i������ʱ������Ҫ��ѯ�������顣���⣬
���ִ洢��ʽ���ܷ�ӳ���ֵܽ��֮��Ĺ�ϵ������ʵ��RightSibling��t��x������Ҳ�Ƚ����ѡ�
��ʵ���У������Ҫʵ����Щ���������ڽ��ṹ�������ŵ�һ�����ӵ���ʹ�ŵ�һ�����ֵܵ���
���ܽϷ����ʵ�����������ˡ�
*/

template <typename T>
class ParentDescrinbingTreeNode
{
public:
	//�ڵ�ֵ
	T data_;
	//���ڵ��������е�����
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
/*��ʼ��*/
{
	if (parent < -1)
		parent_ = -1;
	else
		parent_ = parent;
	data_ = data;
}
