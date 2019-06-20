#pragma once
/*���ӱ�ʾ���еĺ��������ʾ��

���������ǽ�������ͼ7.5 ��ʾ����ʽ�洢����������һ���������һ����С��һά���飬
�����ÿһ��Ԫ������������ɣ�һ����������Ž����Ϣ����һ���������ָ�룬
��ָ��ָ���ɸý�㺢����ɵĵ��������λ�á�������ĽṹҲ����������ɣ�
һ����ź��ӽ����һά�����е���ţ���һ����ָ����ָ����һ�����ӡ�

�ں��ӱ�ʾ���в���˫�ױȽ����ѣ����Һ���ȴʮ�ַ��㣬�������ڶԺ��Ӳ������Ӧ�á�
*/

template <typename T>
class ChildLinkRepresentationChild
/*���������ʾ�����ӽڵ�*/
{
public:
	ChildLinkRepresentationChild(int index=-1, ChildLinkRepresentationChild<T>* next=nullptr):index_(index),next_(next){}
	~ChildLinkRepresentationChild();
public:
	//���иýڵ���±�����
	int index_;
	//�ڵ���ֵ�
	ChildLinkRepresentationChild<T>* next_;
};

template <typename T>
class ChildLinkRepresentationNode
/*���������ʾ�����ڵ�*/
{
public:
	ChildLinkRepresentationNode();
	~ChildLinkRepresentationNode();
	ChildLinkRepresentationNode(T data,ChildLinkRepresentationChild<T>*first_child=nullptr):data_(data),first_child_(first_child){}
public:
	//�ڵ�ֵ
	T data_;
	//�ڵ��һ������
	ChildLinkRepresentationChild<T>* first_child_;
};

template<typename T>
inline ChildLinkRepresentationChild<T>::~ChildLinkRepresentationChild()
{
}

template<typename T>
inline ChildLinkRepresentationNode<T>::ChildLinkRepresentationNode()
{
	first_child_ = nullptr;
}

template<typename T>
inline ChildLinkRepresentationNode<T>::~ChildLinkRepresentationNode()
{
}
