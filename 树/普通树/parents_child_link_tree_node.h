#pragma once
/*˫�׺��ӱ�ʾ��
˫�ױ�ʾ���ǽ�˫�ױ�ʾ���ͺ��ӱ�ʾ�����ϵĽ�������Խ������ĺ��ӽ��ֱ���ɵ�����
ͬʱ��һά����˳��洢���еĸ���㣬
����Ԫ�س��˰�����㱾�����Ϣ�͸ý��ĺ��ӽ�������ͷָ��֮�⣬
������һ���򣬴洢�ý��˫�׽���������е���š�

����һ�ֺ����ֵܱ�ʾ��

����һ�ֳ��õĴ洢�ṹ���䷽���������ģ������У�ÿ����������Ϣ���⣬
�����������ֱ�ָ��ý��ĵ�һ�����ӽ�����һ���ֵܽ���ָ�롣
�����ִ洢�ṹ�£����н��Ĵ洢��ʾ������Ϊ��
typedef struct TreeNode {
elemtype data;
struct TreeNode *son;
struct TreeNode *next;
}NodeType;
*/

class ParentsChildLinkChild
	/*˫�׺��ӱ�ʾ���еĺ��ӽڵ�*/
{
public:
	ParentsChildLinkChild(int index=-1,ParentsChildLinkChild*next=nullptr):index_(index),next_(next){}
	~ParentsChildLinkChild();
public:
	//���溢�����������еĽڵ��±�
	int index_;
	//������һ������
	ParentsChildLinkChild* next_;
};

inline ParentsChildLinkChild::~ParentsChildLinkChild()
{
}

template <typename T>
class ParentsChildLinkNode
/*˫�׺��ӱ�ʾ���еĽڵ�*/
{
public:
	ParentsChildLinkNode();
	ParentsChildLinkNode(T data,int parent=-1, ParentsChildLinkChild* first_child = nullptr):data_(data),first_child_(first_child),parent_(parent){}
	~ParentsChildLinkNode();
public:
	//�ڵ�ֵ
	T data_;
	//��һ������ָ��
	ParentsChildLinkChild* first_child_;
	//���׽ڵ���±�
	int parent_;
};

template<typename T>
inline ParentsChildLinkNode<T>::ParentsChildLinkNode()
{
}

template<typename T>
inline ParentsChildLinkNode<T>::~ParentsChildLinkNode()
{
}
