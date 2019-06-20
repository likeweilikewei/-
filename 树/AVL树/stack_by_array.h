#pragma once
/*�����鶨���ջ*/

template <typename T>
class Stack
{
public:
	Stack();
	~Stack();
	void push(T data);
	void pop();
	T top();
	int size();
	bool empty();

//˽������
private:
	T* stack_;
	int max_size_ = 10;
	//ÿ����������һ��
	const int& increase_size_ = max_size_;
	//top-1��ջ���±꣬ջ����������
	int top_ = 0;
	//ָ��ջ��
	int bottom_ = 0;

//˽�нӿ�
private:
	bool IsFull();
	//��������
	void IncreaseSize();
};

template<typename T>
inline bool Stack<T>::IsFull()
/*�ж��Ƿ�Ϊ��*/
{
	return top_ - bottom_ == max_size_;
}

template<typename T>
inline void Stack<T>::IncreaseSize()
/*��������*/
{
	max_size_ = max_size_ + increase_size_;
	T* old_stack = stack_;
	stack_ = new T[max_size_];
	if (!stack_)
		throw "ERROR:new stack failed.";
	//��������
	int i = 0;
	for (i = 0; i < top_; ++i)
	{
		stack_[i] = old_stack[i];
	}

	//�ͷž�����
	delete old_stack;
	old_stack = nullptr;
}

template<typename T>
inline Stack<T>::Stack()
{
	stack_ = new T[max_size_];
	if (!stack_)
		throw "ERROR:new failed.";
}

template<typename T>
inline Stack<T>::~Stack()
{
	delete stack_;
	stack_ = nullptr;
}

template<typename T>
inline void Stack<T>::push(T data)
/*Ԫ�ؽ�ջ*/
{
	if (IsFull())
		IncreaseSize();
	stack_[top_++] = data;
}

template<typename T>
inline void Stack<T>::pop()
/*Ԫ�س�ջ*/
{
	if (empty())
		throw "ERROR:pop empty stack.";
	top_--;
}

template<typename T>
inline T Stack<T>::top()
/*ȡջ��Ԫ��*/
{
	return stack_[top_-1];
}

template<typename T>
inline int Stack<T>::size()
/*�õ�ջ��Ԫ�ظ���*/
{
	return top_-bottom_;
}

template<typename T>
inline bool Stack<T>::empty()
/*�ж�ջ��Ԫ���Ƿ�Ϊ��*/
{
	return top_==bottom_;
}

