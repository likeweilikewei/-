#pragma once
/*�����ֵܱ�ʾ��

����һ�ֳ��õĴ洢�ṹ���䷽���������ģ������У�ÿ����������Ϣ���⣬
�����������ֱ�ָ��ý��ĵ�һ�����ӽ�����һ���ֵܽ���ָ�롣
�����ִ洢�ṹ�£����н��Ĵ洢��ʾ������Ϊ��*/
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
	//��һ������
	ChildBrotherNode<T>* child_;
	//���ֵ�
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
	//�õ����ڵ�
	ChildBrotherNode<T>* GetRoot();
	//���ø��ڵ�
	void SetRoot(ChildBrotherNode<T>* root);
	//���ҽڵ�ֵ�Ƿ����
	ChildBrotherNode<T>* Search(ChildBrotherNode<T>*root, T data);
	//��ӽڵ�
	void AppendNode(T data, T parent_data);
	//���������
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
/*�����в��ҽڵ�ֵ�Ƿ���ڣ������ڷ��ؿ�ָ�룬�����򷵻���Ӧ�ڵ�*/
{
	if (root == nullptr)
		return nullptr;
	//���淵�ؽ��
	ChildBrotherNode<T>* result = nullptr;
	//����ĵ�ǰ�ڵ�
	ChildBrotherNode<T>* node = root;
	//�������ڵ�
	queue<ChildBrotherNode<T>*>nodes;
	//�ݴ����ڵ���ֵܽڵ�
	ChildBrotherNode<T>* brother = nullptr;
	nodes.push(root);

	//������������ҽڵ�
	while (!nodes.empty())
	{
		//������ǰ�ڵ�
		node = nodes.front();

		//����ǵ�ǰֵ���˳�ѭ��
		if (node->data_ == data)
			return node;

		//���ýڵ㺢�ӽڵ�����У��������ｫ����
		if (node->child_)
		{
			if (node->child_->data_ == data)
				return node->child_;
			nodes.push(node->child_);

			//ֻ���ڵ�һ�����ӵĵط��ŷ��������ֵܣ������Ͳ��ᵼ���ֵܽڵ��ظ������
			brother = node->child_->brother_;
			while (brother)
			{
				if (brother->data_ == data)
					return brother;
				nodes.push(brother);
				brother = brother->brother_;
			}
		}

		//�����ڵ�
		nodes.pop();
	}
	return result;
}

template<typename T>
inline void ChildBrotherTree<T>::AppendNode(T data, T parent_data)
/*��ӽڵ�*/
{
	//����ڵ�
	ChildBrotherNode<T>* node = new ChildBrotherNode<T>(data);

	//�����Ϊ��ֱ�Ӳ���ڵ�Ȼ�󷵻�
	if (root_ == nullptr)
	{
		root_ = node;
		return;
	}

	//���Ҳ���Ľڵ㣬�����ֵܱ�ʾ������������ظ��ڵ�ֵ
	ChildBrotherNode<T>* result_data = Search(GetRoot(), data);
	ChildBrotherNode<T>* result_parent = Search(GetRoot(), parent_data);
	//��ʱ�洢�ڵ�
	ChildBrotherNode<T>* brother = nullptr;

	//�������ֵ���ڲ����룬���߸��ڵ�ֵ������Ҳ������
	if (result_data != nullptr || result_parent == nullptr)
		return;

	//������ڵ㺢�ӽڵ�Ϊ��ֱ��ָ���½ڵ�
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
/*���������*/
{
	cout << "start level order the tree." << endl;
	if (root == nullptr)
		return;

	//����ڵ�
	queue<ChildBrotherNode<T>*>nodes;
	//�ݴ�ڵ�
	ChildBrotherNode<T>* node = root;
	nodes.push(node);
	//�ݴ溢�ӽڵ�
	ChildBrotherNode<T>* child = nullptr;

	//�����ڵ�
	while (!nodes.empty())
	{
		node = nodes.front();

		child = node->child_;
		//����ýڵ��к��ӽڵ���Ҫ�����к��ӷ������
		while (child)
		{
			nodes.push(child);
			child = child->brother_;
		}

		//����ڵ�
		cout << setw(5) << node->data_;
		//�����ڵ�
		nodes.pop();
	}
	cout << endl;
}
