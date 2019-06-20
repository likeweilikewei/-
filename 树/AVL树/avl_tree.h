#pragma once

#include<iostream>
#include<iomanip>
#include<vector>
#include<stack>
#include<algorithm>
#include"avl_tree_node.h"
#include"stack_by_array.h"
#include"queue_by_array.h"

using namespace std;

template <typename T>
struct InputResult {
	//����������ʱ�û�����
	T* datas_array_;
	int datas_len_;
};

template <typename T>
class AvlTree
{
public:
	AvlTree();
	~AvlTree();
	//ɾ����
	void DestroyTree();
	//ɾ���ڵ�
	void Destroy(AvlTreeNode<T>** tree_node_link);

	//�õ����ڵ�
	AvlTreeNode<T>* get_root();
	//�õ����ڵ�ָ�룬�Ӷ����Ըı���ڵ�ָ��
	AvlTreeNode<T>* get_root_link();
	//���ø��ڵ�
	void set_root(AvlTreeNode<T>* root);

	//����ڵ�߶�
	static int CalculateHeight(AvlTreeNode<T>* tree_node);
	//�õ��߶�,Ĭ�ϵõ����ĸ߶�
	static int GetHeight(AvlTreeNode<T>* tree_node = root_);
	//�õ�ƽ�����ӣ�Ĭ�������Ӹ߶�-�Һ��Ӹ߶ȣ�ֻҪ�߶�������2��������ƽ��ģ�������Ҫ��ת
	static int GetFactor(AvlTreeNode<T>*tree_node);

	//LL���������ȥƽ��ĸ��ڵ�Ϊ���ģ�ץס����������ʹ������Ϊ�¸��ڵ㣬ԭ�����Һ��ӵ����������ɸ�������
	static AvlTreeNode<T>* LeftLeftRotation(AvlTreeNode<T>* tree_node);
	//RR�����ͬ�ϣ�ֻ��ץס�Һ������������Һ�����Ϊ�¸��ڵ�
	static AvlTreeNode<T>* RightRightRotation(AvlTreeNode<T>* tree_node);
	//LR�������Χ�Ƹ��ڵ������RR��ת����Χ����ȥƽ��ĸ��ڵ㣬LL��ת
	static AvlTreeNode<T>* LeftRightRotation(AvlTreeNode<T>* tree_node);
	//RL�������Χ��ʧȥƽ����Һ��ӽ���LL��ת���������ڵ�����ӵ��Һ�����ת�����ڵ���Һ��ӣ���Χ�Ƹ��ڵ����RR��ת�������ڵ��Һ�����תΪ�¸��ڵ�
	static AvlTreeNode<T>* RightLeftRotation(AvlTreeNode<T>* tree_node);

	//����ƽ������˺��ӵĽڵ㣬����Ӵ������½ڵ����ϣ����Ų���·��ƽ��
	static AvlTreeNode<T>* Reblanced(AvlTreeNode<T>* tree_node, T data);
	//����ƽ��ɾ���˽ڵ�����
	static AvlTreeNode<T>* ReblanceDelete(AvlTreeNode<T>* tree_node);
	//���ҽڵ�
	static bool Search(const AvlTreeNode<T>*const tree_root, const T& search_data, const AvlTreeNode<T>* &searched_node);
	//����ڵ㣬��ͬʱ���½ڵ�߶ȣ���������ƽ�⣬��Ϊ��Ҫ�ı�ڵ�ָ�����������
	static void Insert(AvlTreeNode<T>*& tree_root, T data);
	//����ڵ�
	void Construct();
	//ɾ���ڵ�
	void Delete(const T& data);
	//ɾ���ڵ㣬�Ľ��棬�õ����ӽڵ��ɾ���ڵ��ɱ���һ�����õݹ飬��˴�����Լ��Ժܶ�
	void Remove(const T& data);

	//����������,Ĭ�ϵݹ��ǰ�����
	void Traversal(AvlTreeNode<T>* tree_root, string order_type = "preorder", int recursion_flag = 1);
	//�ݹ�ǰ�����������
	void RecursionPreorderTraversal(AvlTreeNode<T>* tree_root);
	//�ǵݹ�ǰ�����������
	void NonRecursionPreorderTraversal(AvlTreeNode<T>* tree_root);
	//�ݹ��������������
	void RecursionInorderTraversal(AvlTreeNode<T>* tree_root);
	//�ǵݹ��������������
	void NonRecursionInorderTraversal(AvlTreeNode<T>* tree_root);
	//�ݹ�������������
	void RecursionPostorderTraversal(AvlTreeNode<T>* tree_root);
	//�ǵݹ�������������
	void NonRecursionPostorderTraversal(AvlTreeNode<T>* tree_root);
	//�������������
	void LevelorderTraversal(AvlTreeNode<T>* tree_root);

	//�õ��������Ԫ�أ����������False
	static AvlTreeNode<T>* MaxNode(AvlTreeNode<T>* tree_root);
	//�Ƿ���������СԪ�أ����������False
	static AvlTreeNode<T>* MinNode(AvlTreeNode<T>* tree_root);
	//�õ�ĳһ��Ԫ�ص������������ǰһ���ڵ�
	static AvlTreeNode<T>* PreviousNode(AvlTreeNode<T>* tree_root, const T& data);
	//�õ�ĳһ��Ԫ�ص�����������еĺ�һ��Ԫ��
	static AvlTreeNode<T>* ForwardNode(AvlTreeNode<T>* tree_root, const T& data);

private:
	AvlTreeNode<T>* root_;

	//��¼�û��ڵ���������
	static InputResult<T> Input();
	//�����ݺͲ��뷽������AVL��
	//�������ݺͲ��뷽������avl��
	static AvlTreeNode<T>* ConstructByDatas(void (*pfunc)(AvlTreeNode<T>*&, T), T* datas_array, T array_len);
	//ɾ���������͸����ڵ㣬�������¼���߶Ⱥ�ƽ����
	static void Delete(AvlTreeNode<T>*& tree_root, const T& data);
	//����BSTɾ���ڵ㣬����ƽ�⶯�������и߶����¼���
	static void DeleteBST(AvlTreeNode<T>*& tree_root);
	//ɾ���ڵ㣬�Ľ��棬�������һ��������ɾ�����������߶Ⱥ���תƽ�⣬������������ָ�룬��Ϊ���ܸı�ָ��ָ����˴���ָ�����ã���ʵҲ���Բ�����
	static AvlTreeNode<T>* Remove(AvlTreeNode<T>*& tree_root, const T& data);
};

template<typename T>
AvlTree<T>::AvlTree()
{
	root_ = nullptr;
}

template<typename T>
AvlTree<T>::~AvlTree()
{
	DestroyTree();
}

template<typename T>
void AvlTree<T>::DestroyTree()
{
	Destroy(&root_);
}

template<typename T>
void AvlTree<T>::Destroy(AvlTreeNode<T>** tree_node_link)
{
	if (!*tree_node_link)
		return;
	Destroy(&((*tree_node_link)->left_child_));
	Destroy(&((*tree_node_link)->right_child_));
	delete tree_node_link;
	tree_node_link = nullptr;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::get_root()
{
	return root_;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::get_root_link()
{
	return &root_;
}

template<typename T>
inline void AvlTree<T>::set_root(AvlTreeNode<T>* root)
{
	root_ = root;
}

template<typename T>
int AvlTree<T>::CalculateHeight(AvlTreeNode<T>* tree_node)
/*�������ĸ߶ȣ�Ҷ�ӽڵ��1��ʼ*/
{
	if (!tree_node)
		return 0;
	return max(GetHeight(tree_node->left_child_), GetHeight(tree_node->right_child_)) + 1;
}

template<typename T>
inline int AvlTree<T>::GetHeight(AvlTreeNode<T>* tree_node)
/*�õ����ĸ߶�*/
{
	if (!tree_node)
		return 0;
	return tree_node->height_;
}

template<typename T>
int AvlTree<T>::GetFactor(AvlTreeNode<T>* tree_node)
/*�õ�ƽ�����ӣ��������ֵ����1�����ǲ�ƽ��*/
{
	if (!tree_node)
		return 0;
	return GetHeight(tree_node->left_child_) - GetHeight(tree_node->right_child_);
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::LeftLeftRotation(AvlTreeNode<T>* tree_node)
/*������ת,Χ�Ƹ��ڵ�����������ǵ�����Ϊ�µĸ��ڵ㣬ԭ�����Һ��ӵ��Һ��ӱ�Ϊ�ɸ�������*/
{
	if (!tree_node || !tree_node->left_child_)
		return tree_node;
	
	//������ڵ�����ӣ�Ҳ�����¸��ڵ�
	AvlTreeNode<T>* new_root = tree_node->left_child_;

	tree_node->left_child_ = new_root->right_child_;
	new_root->right_child_ = tree_node;

	//��Ϊ������ת�����¾ɸ����¸��߶ȿ��ܷ����仯���ȸ��¾ɸ��ĸ߶ȣ����ܸ����¸��ĸ߶�
	tree_node->height_ = max(GetHeight(tree_node->left_child_), GetHeight(tree_node->right_child_)) + 1;
	new_root->height_ = max(GetHeight(new_root->left_child_), tree_node->height_)+1;

	return new_root;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::RightRightRotation(AvlTreeNode<T>* tree_node)
/*������ת*/
{
	if (!tree_node || !tree_node->right_child_)
		return tree_node;
	
	//�����¸��ڵ�
	AvlTreeNode<T>* new_root = tree_node->right_child_;

	//��������ת�����¸��ڵ�����Ӹ��ɸ��ڵ���Һ���
	tree_node->right_child_ = new_root->left_child_;
	new_root->left_child_ = tree_node;

	//���½ڵ�ĸ߶ȣ��ȸ��¾ɸ��ڵ�ĸ߶ȣ�Ȼ������¸��ڵ�ĸ߶�
	tree_node->height_ = max(GetHeight(tree_node->left_child_), GetHeight(tree_node->right_child_)) + 1;
	new_root->height_ = max(GetHeight(new_root->right_child_), tree_node->height_) + 1;

	return new_root;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::LeftRightRotation(AvlTreeNode<T>* tree_node)
/*LR��������Ը��ڵ�����Ϊ���Ľ���RR��ת��Ȼ���Ը��ڵ�Ϊ���Ľ���LL��ת*/
{
	if (!tree_node || !tree_node->left_child_ || !tree_node->left_child_->right_child_)
		return tree_node;

	//�ȱ����¸��ڵ�
	AvlTreeNode<T>* new_root;

	//���Ը��ڵ�����Ϊ���Ľ���RR��ת,ֱ�Ӹ�������Ĵ���
	//tree_node->left_child_->right_child_ = new_root->left_child_;
	//new_root->left_child_ = tree_node->left_child_;
	tree_node->left_child_ = RightRightRotation(tree_node->left_child_);

	//�Ը��ڵ�Ϊ���Ľ���LL��ת
	//tree_node->left_child_ = new_root->right_child_;
	//new_root->right_child_ = tree_node;
	new_root = LeftLeftRotation(tree_node);
	return new_root;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::RightLeftRotation(AvlTreeNode<T>* tree_node)
/*����������ȶԸ��ڵ���Һ���Ϊ������LL��ת���ǵ��Һ��ӵ�����Ϊ�����Һ��ӣ�Ȼ��Ը��ڵ���RR��ת��ʹ���Һ���Ϊ�¸�*/
{
	if (!tree_node || !tree_node->right_child_ || !tree_node->right_child_->left_child_)
		return tree_node;

	//�ȶ��Һ��ӽ���LL��ת
	tree_node->right_child_ = LeftLeftRotation(tree_node->right_child_);
	//�ٶԸ��ڵ����RR��ת
	return  RightRightRotation(tree_node);
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::Reblanced(AvlTreeNode<T>* tree_node, T data)
/*����ƽ��*/
{
	if (!tree_node)
		return NULL;

	int factor = GetFactor(tree_node);
	//���û�в�ƽ��������
	if (abs(factor) < 2)
		return tree_node;

	//���ֵС�����ӣ�����LL
	else if (factor > 1 && data < tree_node->left_child_->data_)
		return LeftLeftRotation(tree_node);

	//����������ӣ�����LR
	else if (factor > 1 && data >= tree_node->left_child_->data_)
		return LeftRightRotation(tree_node);

	//����ұ����Ӵ󣬲��Ҳ���ֵ�����Һ�������RR
	else if (factor<-1 && data>=tree_node->right_child_->data_)
		return RightRightRotation(tree_node);

	//����ұ����Ӵ󣬲��Ҳ���ֵС���Һ�������RL
	else if (factor < -1 && data < tree_node->right_child_->data_)
		return RightLeftRotation(tree_node);

	//���������������
	else
		return tree_node;
}

template<typename T>
AvlTreeNode<T>* AvlTree<T>::ReblanceDelete(AvlTreeNode<T>* tree_node)
/*ɾ���ڵ�������ƽ�⣬��Ҫ���ʶ�����ַ�ת����һ�����,������ָ����ܵ��µĽڵ�*/
{
	//Ϊ��ֱ�ӷ���
	if (!tree_node)
		return nullptr;

	//ȡƽ������
	int factor = GetFactor(tree_node);

	//û���ƻ�ƽ���򷵻�
	if (abs(factor) < 2)
		return tree_node;

	//���ʧ�������Ӹ����Һ��ӣ����������Ӹ����Һ�������LL,ע��ɾ������������Ǹߵ������Ǳ���������һ��������ʱ����LLֻ��Ҫ��תһ�Σ�LR��Ҫ��ת����
	else if (factor > 1 && GetHeight(tree_node->left_child_->left_child_) >= GetHeight(tree_node->left_child_->right_child_))
	{
		return LeftLeftRotation(tree_node);
	}

	//���ʧ�������Ӹ����Һ��ӣ������е����ӵ����Һ�������LR
	else if (factor > 1 && GetHeight(tree_node->left_child_->left_child_) < GetHeight(tree_node->left_child_->right_child_))
	{
		return LeftRightRotation(tree_node);
	}

	//���ʧ�������ӵ����Һ��ӣ��Һ����е����Ӹ����Һ��ӣ�����RL
	else if (factor < -1 && GetHeight(tree_node->right_child_->left_child_) < GetHeight(tree_node->right_child_->right_child_))
	{
		return RightLeftRotation(tree_node);
	}

	//���ʧ�������ӵ����Һ��ӣ��Һ����е����ӵ����Һ��ӣ�����RR,ע��ɾ������������Ǹߵ������Ǳ���������һ��������ʱ����RRֻ��Ҫ��תһ�Σ�RL��Ҫ��ת����
	else if (factor < -1 && GetHeight(tree_node->right_child_->left_child_) <= GetHeight(tree_node->right_child_->right_child_))
	{
		return RightRightRotation(tree_node);
	}

	//�������ʧ�ⲻ��ͨ������������ƽ�⣬�Ǵ���״̬������
	else
	{
		//cout << "the avl tree is wrong.";
		//return nullptr;
		throw "the avl tree is wrong.";
	}
}

template<typename T>
bool AvlTree<T>::Search(const AvlTreeNode<T>*const tree_root, const T& search_data, const AvlTreeNode<T>*& searched_node)
/*���ҽڵ㣬������ҵ��򷵻�true��searched_nodeָ����ҵ��Ľڵ㣬���򷵻�false,searched_nodeָ�������ҵ��Ľڵ�*/
{
	//����ڵ�Ϊ��ֱ�ӷ���
	if (!tree_root)
	{
		searched_node = nullptr;
		return false;
	}

	//������ҵ�ֱ�ӷ���
	else if (tree_root->data_ == search_data)
	{
		searched_node = tree_root;
		return true;
	}

	//�������ֵС�ڸ��ڵ�ֵ�������������в���
	else if (tree_root->data_ > search_data)
	{
		//���û�����ӣ���ֱ�ӷ���
		if (!tree_root->left_child_)
		{
			searched_node = tree_root;
			return false;
		}
		//�еĻ���������
		else
		{
			Search(tree_root->left_child_, search_data, searched_node);
		}
	}

	//�������ֵ���ڽڵ�ֵ�����������в���
	else
	{
		if (!tree_root->right_child_)
		{
			searched_node = tree_root;
			return false;
		}
		else
		{
			Search(tree_root->right_child_, search_data, searched_node);
		}
	}
}

template<typename T>
void AvlTree<T>::Insert(AvlTreeNode<T>*& tree_root, T data)
/*����ڵ㣬���¸߶ȣ�����ƽ�⣬Ϊ��ƽ��·���ϵĽڵ㣬��Ҫ�õݹ�*/
{
	//���Ϊ��ֱ�Ӳ��벢���¸߶ȾͿ�����
	if (!tree_root)
	{
		//�����½ڵ�
		AvlTreeNode<T>* new_node = new AvlTreeNode<T>(data);
		if (!new_node)
			throw "ERROR:new node failed.";
		tree_root = new_node;
	}

	//�������ֵС�ڵ�ǰֵ
	else if (data < tree_root->data_)
		Insert(tree_root->left_child_, data);

	//�������ֵ���ڵ�ǰֵ
	else if (data > tree_root->data_)
		Insert(tree_root->right_child_, data);

	//���������
	else
		cout << "can not insert same data." << endl;

	//���¸߶ȣ�������ӵĽڵ㿪ʼ���������������ʱ��û�г�ʼ���߶ȣ�������Ҳ����г�ʼ��
	tree_root->height_ = max(GetHeight(tree_root->left_child_), GetHeight(tree_root->right_child_)) + 1;

	//����ƽ�⣬������ӵ�����ڵ㿪ʼ
	tree_root = Reblanced(tree_root, data);
}

template<typename T>
InputResult<T> AvlTree<T>::Input()
/*��¼�û�����*/
{
	InputResult<T> input_result;
	vector<T>datas_vector;
	T data;

	cout << "please inputs avl tree datas,0 to quit:" << endl;
	while (cin >> data)
	{
		if (data == 0 || data == '0')
			break;
		datas_vector.push_back(data);
	}

	//�������е�����ת��Ϊ����
	int datas_len = datas_vector.size();
	int i = 0;
	T* datas_array = new T[datas_len];

	for (i = 0; i < datas_len; ++i)
	{
		datas_array[i] = datas_vector[i];
	}

	//�����ݷ���ṹ����һ�𷵻�
	input_result.datas_array_ = datas_array;
	input_result.datas_len_ = datas_len;
	return input_result;
}

template<typename T>
void AvlTree<T>::Construct()
/*����avl��*/
{
	InputResult<T> input_result = Input();
	root_ = ConstructByDatas(Insert, input_result.datas_array_, input_result.datas_len_);
}

template<typename T>
void AvlTree<T>::Delete(const T& data)
/*ɾ���ڵ㲢����ƽ�⣬���ܸı���ڵ�ָ��*/
{
	//���ڵ�
	AvlTreeNode<T>* tree_root = root_;
	//������ҵ��Ľڵ㣬����û����
	const AvlTreeNode<T>* searched_node = nullptr;
	//�Ȳ��ң����������ɾ��������������
	if (Search(tree_root, data, searched_node))
	{
		Delete(tree_root, data);
	}

	//���¸����¸�
	root_ = tree_root;
}

template<typename T>
inline void AvlTree<T>::Remove(const T& data)
/*�Ľ���ɾ���ڵ�*/
{
	const AvlTreeNode<T>* node = nullptr;
	if (Search(root_, data, node))
		root_ = Remove(root_, data);
}

template<typename T>
void AvlTree<T>::Delete(AvlTreeNode<T>*&tree_root,const T& data)
/*ɾ���ڵ㣬����ڵ���ڣ����ն������������ɾ���ڵ㣬ѡȡ��ɾ�ڵ����������ڵ���Ϊ�¸���Ȼ�������ԭ���������������ڵ�ĸ��ڵ㿪ʼ���ϵ���*/
{
	//Ϊ��ֱ�ӷ���
	if (!tree_root)
		return;

	//���ҽڵ�
	if (data == tree_root->data_)
	{
		//ɾ���ڵ�
		DeleteBST(tree_root);
	}
	else if (data < tree_root->data_)
	{
		Delete(tree_root->left_child_,data);
	}
	else
	{
		Delete(tree_root->right_child_,data);
	}

	if (tree_root != NULL)
	{
		//�����������ĸ��ĸ߶�
		tree_root->height_ = max(GetHeight(tree_root->left_child_), GetHeight(tree_root->right_child_)) + 1;

		//��ʧȥƽ��Ľڵ�����ƽ��
		tree_root = ReblanceDelete(tree_root);
	}
}

template<typename T>
void AvlTree<T>::DeleteBST(AvlTreeNode<T>*& tree_root)
/*ɾ���ڵ㣬���¸߶ȣ�������ƽ���ⲿ��*/
{
	//���Ϊ���Թ�
	if (!tree_root)
		return;

	//��ɾ���ڵ�
	AvlTreeNode<T>* delete_node = nullptr;
	//�¸�
	AvlTreeNode<T>* new_root;
	//�¸����ڵ㣬����ƴ���¸�������
	AvlTreeNode<T>* new_root_parent;
	//����·���ڵ㣬�ӵ����ϸ��¸߶Ⱥ���ƽ��
	Stack<AvlTreeNode<T>*>nodes;

	//������Һ��Ӷ�Ϊ������Ϊ�վͿ�����
	if (!tree_root->left_child_ && !tree_root->right_child_)
		tree_root = nullptr;

	//�������Ϊ�������¶Խ��Һ���
	else if (!tree_root->left_child_)
	{
		delete_node = tree_root;
		tree_root = tree_root->right_child_;
		delete delete_node;
		delete_node = nullptr;
	}

	//����Һ���Ϊ�������¶Խ�����
	else if (!tree_root->right_child_)
	{
		delete_node = tree_root;
		tree_root = tree_root->left_child_;
		delete delete_node;
		delete_node = nullptr;
	}

	//�������Ϊ�գ���ѡȡ���������ڵ���Ϊ�¸������¸߶Ⱥ�����ƽ�⣬�������Ǵ��¸��ĸ��ڵ�����֪��ɾ���ڵ�Ϊֹ
	else
	{
		new_root = tree_root->left_child_;
		new_root_parent = tree_root;
		nodes.push(new_root_parent);
		//�ҵ��¸�
		while (new_root->right_child_)
		{
			new_root_parent = new_root;
			new_root = new_root->right_child_;
			nodes.push(new_root_parent);
		}

		//���¸�ֵ�����ɸ��������ƶ��¸�
		tree_root->data_ = new_root->data_;

		//����¸����Ǿɸ�������,ֱ��ɾ���ظ����¸�
		if (new_root_parent == tree_root)
		{
			tree_root->left_child_ = new_root->left_child_;
		}
		//����Ҫ�Խ��¸������ӣ��¸�û���Һ��ӣ�
		else
		{
			new_root_parent->right_child_ = new_root->left_child_;
		}

		//ɾ���¸��ڵ�
		delete new_root;
		new_root = nullptr;

		//���´��¸����ڵ㿪ʼ���½ڵ�߶�
		AvlTreeNode<T>* tmp_node = nullptr;
		AvlTreeNode<T>* tmp_node_parent = nullptr;
		while (!nodes.empty())
		{
			tmp_node = nodes.top();
			nodes.pop();
			//���¸߶�
			tmp_node->height_= max(GetHeight(tmp_node->left_child_), GetHeight(tmp_node->right_child_)) + 1;

			if (!nodes.empty())
			{
				//�õ����ڵ�
				tmp_node_parent = nodes.top();
				//������Һ��ӣ��򷵻ص���ָ��ָ���Һ��ӣ�֮������ô������Ϊnodes�洢�Ķ��ǿ����ڵ�ָ�룬�޷��ı�ԭ���Ľڵ�ָ��
				if (tmp_node_parent->right_child_ == tmp_node)
				{
					tmp_node_parent->right_child_ = ReblanceDelete(tmp_node);
				}
				else if (tmp_node_parent->left_child_ == tmp_node)
				{
					tmp_node_parent->left_child_ = ReblanceDelete(tmp_node);                                    
				}
			}
			//���nodesΪ��˵��ֻ����һ��Ԫ��
			else
			{
				tree_root = ReblanceDelete(tmp_node);
			}
		}
	}
	//�����������ĸ��ĸ߶�
	if (tree_root != nullptr)
		tree_root->height_ = max(GetHeight(tree_root->left_child_), GetHeight(tree_root->right_child_)) + 1;
}

template<typename T>
AvlTreeNode<T>* AvlTree<T>::Remove(AvlTreeNode<T>*& tree_root, const T& data)
/*ɾ�����еĽڵ㣬����߶ȣ�����ƽ��*/
{
	if (tree_root == nullptr)
		return NULL;

	//�ݹ��жϣ����ֵС�ڸ�ֵ�������������,ɾ���ڵ㲢����ƽ��
	if (data < tree_root->data_)
	{
		//����������ɾ���ڵ�
		tree_root->left_child_ = Remove(tree_root->left_child_, data);

		//�ж��Ƿ�ƽ�⣬��Ϊ��ɾ�������������ֻ�������������߶�С��������2
		if (GetHeight(tree_root->right_child_) - GetHeight(tree_root->left_child_) > 1)
		{
			//RL���
			if (GetHeight(tree_root->right_child_->right_child_) < GetHeight(tree_root->right_child_->left_child_))
				tree_root = RightLeftRotation(tree_root);
			//RR�����ɾ���ڵ���������������������һ���ߣ�����RR��RL�����ԣ�����RR���򵥣�ֻ��Ҫ��תһ�Σ�RL��Ҫ��ת����
			else
				tree_root = RightRightRotation(tree_root);
		}
	}
	//ɾ���ڵ�����������
	else if (data > tree_root->data_)
	{
		//����������ɾ���ڵ�
		tree_root->right_child_ = Remove(tree_root->right_child_, data);

		//�ж��Ƿ�����ƽ�⣬��Ϊɾ�������������Ľڵ㣬��˲�ƽ��ֻ�������������߶ȱ���������1
		if (GetHeight(tree_root->left_child_) - GetHeight(tree_root->right_child_) > 1)
		{
			//LL��������������������Һ���һ���ߵ�ʱ����LL��LR��Ҫ������ת
			if (GetHeight(tree_root->left_child_->left_child_) >= GetHeight(tree_root->left_child_->right_child_))
				tree_root = LeftLeftRotation(tree_root);
			//LR�����
			else
				tree_root = LeftRightRotation(tree_root);
		}
	}
	//�ҵ�ɾ���ڵ�
	else
	{
		//���������������Ϊ�գ���ɾ���ڵ��ͬʱ������Ҳ��Ҫƽ�⣬�õݹ�
		//����������Ϊ�գ�������������ȡ���������ڵ���Ϊ�¸���ͬʱɾ���������е����ڵ㣬��Ϊ��������ཱུ�͸߶ȣ�
		//����ԭ������ƽ�ⲻ����ƣ���˲������򵥣�������Ҫ��ԭ���ĸ���ƽ��
		if (tree_root->left_child_ != nullptr && tree_root->right_child_ != nullptr)
		{
			//����¸�
			AvlTreeNode<T>* new_root;

			//��������������¸�Ϊ���������ڵ�,���¸�Ϊ���������ڵ�
			if (GetHeight(tree_root->left_child_) >= GetHeight(tree_root->right_child_))
			{
				new_root = MaxNode(tree_root->left_child_);
				//���¸�ֵ�����ɸ�ʵ�ָ����滻
				tree_root->data_ = new_root->data_;
				//����������ɾ���¸��ڵ㣬���Ҳ��ᵼ��ԭ��ʧȥƽ��
				tree_root->left_child_ = Remove(tree_root->left_child_, new_root->data_);
			}

			//���������ߣ�ѡȡ��������С�ڵ�Ϊ�¸���������������ɾ���¸�������ԭ�����᲻ƽ��
			else
			{
				new_root = MinNode(tree_root->right_child_);
				//���¸������ɸ���ʵ�ָ����滻
				tree_root->data_ = new_root->data_;
				//����������ɾ���ɸ�
				tree_root->right_child_ = Remove(tree_root->right_child_, new_root->data_);
			}
		}

		//������������ȫ���������߶�Ϊ��ʱ��ֱ�ӷ�����Ӧ�ڵ㲢��ɾ���ڵ㣬Ҳ�ǵݹ���ֹ����
		else
		{
			AvlTreeNode<T>* tmp = tree_root;
			//���¶Խӽڵ�
			tree_root = (tree_root->left_child_ != nullptr) ? tree_root->left_child_ : tree_root->right_child_;
			//ɾ���ڵ�
			delete tmp;
			tmp = nullptr;
		}
	}

	//���¼���߶ȣ����һ���ڵ����Ϊ��
	if (tree_root != nullptr)
		tree_root->height_ = CalculateHeight(tree_root);

	//�����¸��ڵ�ָ��
	return tree_root;
}

template<typename T>
inline void AvlTree<T>::Traversal(AvlTreeNode<T>* tree_root, string order_type, int recursion_flag)
/*����������*/
{
	if (order_type == "preorder" && recursion_flag == 1)
	{
		cout << "start recursion preorder traversal the tree." << endl;
		RecursionPreorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "inorder" && recursion_flag == 1)
	{
		cout << "start recursion inporder traversal the tree." << endl;
		RecursionInorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "postorder" && recursion_flag == 1)
	{
		cout << "start recursion postorder traversal the tree." << endl;
		RecursionPostorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "preorder" && recursion_flag == 0)
	{
		cout << "start non recursion preorder traversal the tree." << endl;
		NonRecursionPreorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "inorder" && recursion_flag == 0)
	{
		cout << "start non recursion inorder traversal the tree." << endl;
		NonRecursionInorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "postorder" && recursion_flag == 0)
	{
		cout << "start non recursion postorder traversal the tree." << endl;
		NonRecursionPostorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else if (order_type == "levelorder")
	{
		cout << "start levelorder traversal the tree." << endl;
		LevelorderTraversal(tree_root);
		cout << endl;
		return;
	}
	else {
		cout << "parameter is error,chose default traversal." << endl;
		RecursionPreorderTraversal(tree_root);
		cout << endl;
		return;
	}
}

template<typename T>
inline void AvlTree<T>::RecursionPreorderTraversal(AvlTreeNode<T>* tree_root)
/*�ݹ�ǰ�����������*/
{
	if (!tree_root)
		return;
	cout << setw(5) << tree_root->data_;
	RecursionPreorderTraversal(tree_root->left_child_);
	RecursionPreorderTraversal(tree_root->right_child_);
}

template<typename T>
inline void AvlTree<T>::NonRecursionPreorderTraversal(AvlTreeNode<T>* tree_root)
/*�ǵݹ�ǰ����������������ÿ⺯����ջ*/
{
	if (!tree_root)
		return;

	//������ǰ�ڵ�
	AvlTreeNode<T>* tmp_node = tree_root;
	//����·���Ķ�ջ����ջ�����������Ӻ͸��Ѿ��������ָ��ָ���Һ��ӣ���ջ��ǰ�ڵ�
	stack<AvlTreeNode<T>*>nodes;

	//��tmp_node�жϽ�����Ϊ�˵�һ���ܽ�ȥ��֮���Բ�����������ջ����Ϊ�������һ�ν�ջ����Ҫ�ж��������
	while (tmp_node || !nodes.empty())
	{
		//�������while������ӵ�ǰ�ڵ㵽�����ӵ�·��
		while (tmp_node)
		{
			nodes.push(tmp_node);
			//ǰ�������������ڵ�
			cout << setw(5) << tmp_node->data_;
			tmp_node = tmp_node->left_child_;
		}

		//�Ӷ�ջ��ȡ��ջ��Ԫ�أ�����ָ��ָ���Һ��ӣ���������Ĺ��̣��Һ��ӵ��ɸ������������
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
			tmp_node = tmp_node->right_child_;
			//�����������Ӻ͸�������Ԫ��
			nodes.pop();
		}
	}
}

template<typename T>
inline void AvlTree<T>::RecursionInorderTraversal(AvlTreeNode<T>* tree_root)
/*�ݹ��������������*/
{
	if (!tree_root)
		return;
	RecursionInorderTraversal(tree_root->left_child_);
	cout << setw(5) << tree_root->data_;
	RecursionInorderTraversal(tree_root->right_child_);
}

template<typename T>
inline void AvlTree<T>::NonRecursionInorderTraversal(AvlTreeNode<T>* tree_root)
/*�ǵݹ��������������*/
{
	if (!tree_root)
		return;

	//��ʱ�ڵ�
	AvlTreeNode<T>* tmp_node=tree_root;
	//����·���ڵ�Ķ�ջ
	Stack<AvlTreeNode<T>*>nodes;

	//��ʼ�����ڵ�,���ܵ�����tmp_node��Ϊ��������Ϊ���һ���ڵ��Һ��ӿ���Ϊ�գ���ʱ����Ҫ�����ж�
	while (tmp_node||!nodes.empty())
	{
		//����ǰ�ڵ�ѭ����������
		while (tmp_node)
		{
			nodes.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		//��ת���򣬵������Ӵ洢���ˣ��������Ӻ͸��ڵ㣬Ȼ���ջ��Ȼ����Һ��ӿ�ʼ��������
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
			cout << setw(5) << tmp_node->data_;
			tmp_node = tmp_node->right_child_;
			nodes.pop();
		}
	}
}

template<typename T>
inline void AvlTree<T>::RecursionPostorderTraversal(AvlTreeNode<T>* tree_root)
/*�ݹ�������������*/
{
	if (!tree_root)
		return;
	RecursionPostorderTraversal(tree_root->left_child_);
	RecursionPostorderTraversal(tree_root->right_child_);
	cout << setw(5) << tree_root->data_; 
}

template<typename T>
inline void AvlTree<T>::NonRecursionPostorderTraversal(AvlTreeNode<T>* tree_root)
/*�ǵݹ�������������*/
{
	if (!tree_root)
		return;

	//��ʱ�ڵ�
	AvlTreeNode<T>* tmp_node=tree_root;
	//�����ʵĽڵ㣬��������Һ����Ƿ��Ѿ������ʣ����ܴ�����ڵ㣬Ȼ�󵯳�
	AvlTreeNode<T>* lase_visit_node=nullptr;
	//���·�����Һ��Ӵ���󵯳�
	Stack<AvlTreeNode<T>*>nodes;
	
	while (tmp_node || !nodes.empty())
	{
		//���浽����ĺ���
		while (tmp_node)
		{
			nodes.push(tmp_node);
			tmp_node = tmp_node->left_child_;
		}

		//��ʼ����ڵ�
		if (!nodes.empty())
		{
			tmp_node = nodes.top();
			//����Һ��Ӵ��������Ϊ�վʹ�����ڵ㣬����ջ
			if (tmp_node->right_child_ == nullptr || tmp_node->right_child_ == lase_visit_node)
			{
				cout << setw(5) << tmp_node->data_;
				nodes.pop();
				//��ǵ�ǰ�ڵ��Ѿ��������
				lase_visit_node = tmp_node;
				//��һ��ѭ�����Զ�������һ���ڵ�
				tmp_node = nullptr;
			}
			//����Һ��Ӳ�Ϊ����û�д������ת���Һ���
			else
			{
				tmp_node = tmp_node->right_child_;
			}
		}
	}
}

template<typename T>
inline void AvlTree<T>::LevelorderTraversal(AvlTreeNode<T>* tree_root)
/*�������*/
{
	if (!tree_root)
		return;
	//����ڵ㣬�������ȴ����Ƚ�ȥ�ģ�����ö���
	Queue<AvlTreeNode<T>*>nodes;
	AvlTreeNode<T>* tmp_node = tree_root;
	nodes.push(tmp_node);
	while (!nodes.empty())
	{
		tmp_node = nodes.front();
		nodes.pop();
		cout << setw(5) << tmp_node->data_;
		//����������Ƚ��������
		if (tmp_node->left_child_)
			nodes.push(tmp_node->left_child_);
		if (tmp_node->right_child_)
			nodes.push(tmp_node->right_child_);
	}
}

template<typename T>
AvlTreeNode<T>* AvlTree<T>::MaxNode(AvlTreeNode<T>* tree_root)
/*�õ����ڵ�*/
{
	AvlTreeNode<T>* node = tree_root;
	if (!tree_root)
		return nullptr;

	while (node->right_child_)
		node = node->right_child_;
	return node;
}

template<typename T>
AvlTreeNode<T>* AvlTree<T>::MinNode(AvlTreeNode<T>* tree_root)
/*�õ�������С�ڵ�*/
{
	AvlTreeNode<T>* node = tree_root;
	if (!tree_root)
		return NULL;

	while (node->left_child_)
		node = node->left_child_;
	return node;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::PreviousNode(AvlTreeNode<T>* tree_root, const T& data)
/*�õ�Ԫ������������е�ǰһ��Ԫ�أ����������е����Ԫ�أ����û�������ֵС�ڵ�ǰ�ڵ�ĸ��ڵ㣬����ҵ����ڵ㻹��������*/
{
	AvlTreeNode<T>* node = tree_root;
	//���ҵ���ǰһ���ڵ�
	AvlTreeNode<T>* previous_node = nullptr;

	if (!node)
		return NULL;

	//��Ϊ�����Ȳ��ҵ���ǰ�ڵ�
	Stack<AvlTreeNode<T>*>nodes;
	while (node)
	{
		if (node->data_ == data)
			break;
		nodes.push(node);
		if (node->data_ > data)
			node = node->left_child_;
		else if (node->data_ < data)
			node = node->right_child_;
	}

	//���û�ҵ��򷵻ؿ�
	if (!node)
		return nullptr;

	//����ҵ����Ȳ������������ڵ�
	if (node->left_child_)
		previous_node = MaxNode(node->left_child_);

	//���û������������ҵ�һ��С�ڽڵ�ֵ�ĸ��ڵ�
	else if (!nodes.empty())
	{
		while (!nodes.empty())
		{
			node = nodes.top();
			if (data > node->data_)
			{
				previous_node = node;
				break;
			}
			else
				nodes.pop();
		}
	}
	else
		previous_node = nullptr;

	return previous_node;
}

template<typename T>
AvlTreeNode<T>* AvlTree<T>::ForwardNode(AvlTreeNode<T>* tree_root, const T& data)
/*���ҽڵ�����������еĺ�һ��Ԫ�أ������������в�����С�ڵ㣬���û������ҵ�һ�����ڽڵ�ֵ�ĸ��ڵ�*/
{
	if (!tree_root)
		return NULL;

	AvlTreeNode<T>* node = tree_root;
	//���ҵĺ�һ���ڵ�
	AvlTreeNode<T>* forward_node = nullptr;
	//��Ÿ��ڵ�·��
	Stack<AvlTreeNode<T>*>nodes;

	//�Ȳ�������ڵ�
	while (node)
	{
		if (node->data_ == data)
			break;
		nodes.push(node);
		if (node->data_ < data)
		{
			node = node->right_child_;
		}
		else
			node = node->left_child_;
	}

	//���û�в��ҵ��򷵻ؿ�ָ��
	if (!node)
		return nullptr;

	//���ҵ��˽ڵ���Ȳ鿴�������е���С�ڵ�
	//����������������������
	if (node->right_child_)
		forward_node = MinNode(node->right_child_);
	//�и��ڵ�Ͳ��Ҹ��ڵ�
	else if (!nodes.empty())
	{
		//�鵽���ڵ㻹û�з���Ҫ��ģ�����Ĭ�Ϸ��ص���NULL
		while (!nodes.empty())
		{
			node = nodes.top();
			if (node->data_ > data)
			{
				forward_node = node;
				break;
			}
			else
				nodes.pop();
		}

		//����ҵ����ڵ㻹��û�У��򷵻�NULL
		if (nodes.empty())
			forward_node = nullptr;
	}
	else
		forward_node = nullptr;
	return forward_node;
}

template<typename T>
inline AvlTreeNode<T>* AvlTree<T>::ConstructByDatas(void(*pfunc)(AvlTreeNode<T>*&, T), T* datas_array, T array_len)
/*�������ݹ���AVL��*/
{
	if (array_len <= 0)
		return nullptr;

	int i;
	AvlTreeNode<T>* root=nullptr;
	
	//����ÿ�����ݹ���
	for (i = 0; i < array_len; ++i)
	{
		pfunc(root, datas_array[i]);
	}
	return root;
}

