#pragma once
#pragma warning(disable : 4996)
#include<vector>
#include<iomanip>
#include<iostream>
#include<string>

using namespace std;
/*���������ڵ��������

�շ������Ĵ洢�ṹ����Ҳ��һ�ֶ������ṹ��
���ִ洢�ṹ���ʺϱ�ʾ����Ҳ�ʺϱ�ʾɭ�֡�
������˫�ױ�ʾ��*/

template <typename T>
class HuffmanTreeNode
{
public:
	HuffmanTreeNode();
	HuffmanTreeNode(T weight, int parent = -1, int left_child = -1,int right_child=-1):weight_(weight),parent_(parent),left_child_(left_child),right_child_(right_child){}
	~HuffmanTreeNode();
public:
	//˫�ױ�ʾ���еĸ��ڵ��±�,-1��ʾ���ڵ�
	int parent_;
	//�����±꣬���Һ��Ӷ�Ϊ-1���ʾҶ���
	int left_child_;
	//�Һ����±�
	int right_child_;
	//Ȩ��
	T weight_;
};

template<typename T>
inline HuffmanTreeNode<T>::HuffmanTreeNode()
{
	parent_ = -1;
	left_child_ = -1;
	right_child_ = -1;
}

template<typename T>
inline HuffmanTreeNode<T>::~HuffmanTreeNode()
{
}


template <typename T>
class HuffmanTree
{
public:
	HuffmanTree(){}
	HuffmanTree(vector<T>weights):weights_(weights){}
	~HuffmanTree(){}
public:
	//�õ�Ȩ������
	vector<T>get_weights();
	//����Ȩ������
	void set_weights(vector<T>weights);
	//�����������
	void ConstructTree();
	//�õ�ǰn��������СȨ�صĸ��ڵ��±�,����-1��ʾ������
	int GetMin(int n);
	//������״��ӡ��������
	void Show();
	//��ÿ��Ȩ��Ҷ�ӽڵ���б���
	void HuffmanCode();
	//��ʾ����
	void ShowCode();
private:

	//��һ�ι����������б��룬��������Ӧ����
	vector<string> HuffmanCodeFromLeaf(vector<HuffmanTreeNode<T>>nodes);
	//���������룬�Ӹ��ڵ㿪ʼ����
	vector<string> HuffmanCodeFromRoot(vector<HuffmanTreeNode<T>>nodes);
	//�ڸ���λ�ô�ӡ��,���ڵ���n�����Ƶĵط���ӡ
	//void ShowWithLocation(HuffmanTreeNode<T>node, int n, int to_be_printed);
private:
	//����ԭ����Ȩ������
	vector<T>weights_;
	//����ڵ㣬��ʼ����ɭ�֣���󱣴��������
	vector<HuffmanTreeNode<T>>nodes_;
	//�������������
	vector<string>codes_;
};

template<typename T>
inline vector<T> HuffmanTree<T>::get_weights()
/*�õ�Ȩ������*/
{
	return weights_;
}

template<typename T>
inline void HuffmanTree<T>::set_weights(vector<T> weights)
/*����Ȩ������*/
{
	weights_ = weights;
}

template<typename T>
void HuffmanTree<T>::ConstructTree()
/*���������*/
{
	if (weights_.empty())
		return;

	//�ȳ�ʼ�����й��������ڵ㣬Ҷ�ӽڵ���n�������ܽ����Ϊ2n-1��
	//��ʱ�ڵ�
	HuffmanTreeNode<T>node;
	node.parent_ = -1;
	node.left_child_ = -1;
	node.right_child_ = -1;

	//����Ȩ�������ȳ�ʼ�����нڵ�Ϊ��
	typename vector<T>::const_iterator iter;
	for (iter = weights_.begin(); iter != weights_.end(); iter++)
	{
		node.weight_ = *iter;
		nodes_.push_back(node);
	}

	//�������������ڵ�Ҳ����
	for (int i = 0; i < (int)weights_.size() - 1; i++)
	{
		nodes_.push_back(node);
	}

	//���ɷ�Ҷ�ӽڵ㣬ÿ��ѡȡȨ����С�ĸ��ڵ���ϳ�һ���½ڵ㣬Ȩ��С����Ϊ����
	//Ȩ����
	int n = weights_.size();
	//�������ڵ���
	int total = 2 * n - 1;
	//������СȨ�ظ��ڵ��±�
	int min_index;
	//��С���ڵ��±�
	int second_min_index;
	for (int i = n; i < total; i++)
	{
		//�õ�Ȩ����С�������ڵ�
		min_index = GetMin(i);
		second_min_index = GetMin(i);
		//���û����С�������ڵ��򱨴�
		if (min_index == -2 || second_min_index == -2)
			throw "no two min weight";
		//�õ��½ڵ�
		nodes_[i].left_child_ = min_index;
		nodes_[i].right_child_ = second_min_index;
		nodes_[i].weight_ = nodes_[min_index].weight_ + nodes_[second_min_index].weight_;
		nodes_[i].parent_ = -1;
		//���º��ӽڵ�ĸ��ڵ���Ϣ
		nodes_[min_index].parent_ = i;
		nodes_[second_min_index].parent_ = i;
	}
}

template<typename T>
int HuffmanTree<T>::GetMin(int n)
/*�õ�ǰn��������Ȩ����С�ĸ��ڵ��±�*/
{
	T min_weight;
	int index=-1;
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (nodes_[i].parent_ == -1)
		{
			if (flag)
			{
				if (min_weight > nodes_[i].weight_)
				{
					min_weight = nodes_[i].weight_;
					index = i;
				}
			}
			//��һ��ֱ�ӳ�ʼ��
			else
			{
				min_weight = nodes_[i].weight_;
				flag = true;
				index = i;
			}
		}
	}
	//�����ҵ��Ľڵ㸸�ڵ���Ϊ-2�������´�ɸѡ����С�ڵ�ɸѡ��
	if (index >= 0 && index < n)
		nodes_[index].parent_ = -2;
	return index;
}

template<typename T>
inline void HuffmanTree<T>::Show()
/*��ӡ��*/
{
	cout << "start show tree:" << endl;
	if (nodes_.empty())
	{
		cout << "tree is empty." << endl;
		return;
	}
	//�õ����ڵ�
	for (int i=0;i<(int)nodes_.size();i++)
	{
		cout << setw(6) << "index: " << setw(6) << i << "  weight: " << nodes_[i].weight_ << "  parent: " << nodes_[i].parent_;
		cout << "  left child:  " << nodes_[i].left_child_ << "  right child:  " << nodes_[i].right_child_ << endl;
	}
}

template<typename T>
inline void HuffmanTree<T>::HuffmanCode()
/*������������ƺ���*/
{
	//�ӽڵ㵽���ڵ����
	//codes_ = HuffmanCodeFromLeaf(nodes_);
	//�Ӹ��ڵ㵽Ҷ�ӽڵ����
	codes_ = HuffmanCodeFromRoot(nodes_);
}

template<typename T>
inline void HuffmanTree<T>::ShowCode()
/*��ʾ����*/
{
	cout << "start show huffman codes." << endl;
	//for (vector<string>::const_iterator iter = codes_.begin(); iter != codes_.end(); iter++)
	for(int i=0;i<codes_.size();i++)
	{
		cout << "weight: " << setw(10) << weights_[i] <<"  code: "<< setw(10) << codes_[i] << endl;
	}
	cout << endl;
}

template<typename T>
vector<string> HuffmanTree<T>::HuffmanCodeFromLeaf(vector<HuffmanTreeNode<T>> nodes)
/*��Ҷ�ӽڵ㿪ʼ����*/
{
	if (nodes.empty())
		return vector<string>();

	//���浱ǰ�ڵ�
	HuffmanTreeNode<T>node;
	//���������
	vector<string>codes;
	//����һ������,�������ֻ��Ҷ�ӽڵ����,��һ����Ϊ���ܴ���ֻ��һ���ַ���Ҫ����
	int n = (nodes.size() + 1) / 2+1;
	//char* code = new char[n];

	//code[n - 1] = '\0';
	//Ҷ�ӽڵ����
	int j = 0;

	//��Ҷ�ӽڵ㿪ʼ����
	for (int i = 0; i < (int)nodes.size(); i++)
	{
		//����Ҷ�ӽڵ�����
		if (nodes[i].left_child_ != -1 || nodes[i].right_child_ != -1)
			continue;
		//ָ��ǰ����ֵ,���ָ��code�б���Ŀ�ͷ�����㿽������
		//����ѭ���ڲ��ſ���ÿ�ζ�������Ӧ���±���
		int start = n - 1;
		//�鿴���ڵ㣬����ڵ��Ǹ��ڵ��������������0���������1����Ϊ�Ǵ�Ҷ�ӽڵ㿪ʼ���룬���code�����һ����ǰ��ӱ���
		node = nodes[i];
		//��ǰ�ķ��ʽڵ��±�
		int current = i;
		//�������
		string code;
		while (node.parent_ != -1)
		{
			//���ӽڵ������0��codeĩβ
			if (nodes[node.parent_].left_child_ == current)
				code.insert(code.begin(), '0');
			else if (nodes[node.parent_].right_child_ == current)
				code.insert(code.begin(), '1');
			else
			{
				Show();
				throw "wrong huffman nodes.";
			}
			//���µ�ǰ����Ľڵ��±�
			current = node.parent_;
			//����ǰ�ڵ�ָ�򸸽ڵ�
			node = nodes[node.parent_];
		}
		//�����뿽�������������У����Ϊһ���ַ�����Ҫ���룬�᷵�ؿ�codes
		//windows�»����
		//strcpy(codes[j++], code + start);
		//Ҳ�����ǽ�����ָ�븴�ƣ�ÿ�ζ����д��һ�εı��룬���Ա����ø���
		//�����ָ��ĸ��Ʊ�����ָ�����飬������vector����vector����Ҫ��string��ΪԪ�ط���
		codes.push_back(code);
		//��memcpyҲ������Դ�����С����strncpyҲ����ȷ�������С��������ֹ����
		//strncpy(codes[j++],code+start,)
	}

	//ɾ��code
	//delete code;
	//code = nullptr;
	//���ر���
	return codes;
}

template<typename T>
inline vector<string> HuffmanTree<T>::HuffmanCodeFromRoot(vector<HuffmanTreeNode<T>> nodes)
/*���������룬�Ӹ��ڵ㿪ʼ����,�������и��ƴ��Σ��������Զ�weight���޸Ķ�����Ӱ�쵽ԭ������*/
{
	if (nodes.empty())
		return vector<string>();

	//�Ƚ�����weight��Ϊ0����weight=0ʱ�����Һ��Ӷ�û���ʣ�weight=1ʱ�����ӱ������ˣ�weight=2
	//�������Һ��Ӷ��������ˣ���ʱ��Ҫ���±�ָ���׽ڵ㣬�����������һ��
	for (typename vector<HuffmanTreeNode<T>>::iterator iter = nodes.begin(); iter != nodes.end(); iter++)
		(* iter).weight_ = 0;

	//Ҷ�ӽڵ����
	int n = (nodes.size() + 1) >> 1;
	//��������±����Ҷ�ӽڵ��±�һһ��Ӧ��Ϊ�˷���ֱ�Ӳ���ǵ�һ���ڵ㣬��������ｫ�ڵ㶼����ռ�
	vector<string>codes(n);
	//���浥������
	string code;
	//�Ӹ��ڵ㿪ʼ����,Ϊ-1ʱ����
	int current = nodes.size()-1;

	//ѭ����������������ǰ�����
	//�Ӹ��ڵ㿪ʼǰ����������ص����ڵ㣬֪�����ڵ㸸�ڵ㣬�������
	while (current != -1)
	{
		//����������û���ʣ����ȷ���������
		if (nodes[current].weight_ == 0)
		{
			//�����ñ�־��ʾ�����������ʹ�
			nodes[current].weight_ = 1;
			//�����������Ϊ���������������������ӱ���
			if (nodes[current].left_child_ != -1)
			{
				//��ӱ���
				code.append("0");
				//����ǰ�±�����Ϊ����
				current = nodes[current].left_child_;
			}
		}
		//�����������������
		else if (nodes[current].weight_ == 1)
		{
			//���ñ�־��ʾ������������������
			nodes[current].weight_ = 2;
			//�����������Ϊ�������������
			if (nodes[current].right_child_ != -1)
			{
				//��ӱ���
				code.append("1");
				//���±�����Ϊ�Һ���
				current = nodes[current].right_child_;
			}
			//�Һ���Ϊ��
			else
			{
				//�������ҲΪ������Ҷ�ӽڵ㣬��ӱ���
				if (nodes[current].left_child_ == -1)
				{
					codes[current] = code;
				}
			}
		}
		//������������������������
		else
		{
			//����ǰ�±���Ϊ���ڵ��±�
			current = nodes[current].parent_;
			//ɾ��һ������
			//����ص����ڵ㣬��ʱ���ַ���Ϊ�գ�����ɾ��
			if (current != -1)
				code.erase(code.end() - 1);
		}
	}
	return codes;
}

