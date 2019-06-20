#pragma once
/*��������ջ����һ������,��ջ��������β��������ӣ�����ʱ�����ݵ�����һ����ջ��Ȼ�󵯳�ջ�����ٵ��ض�ջ����
Ϊ�˷���ȡ���ף�������Ԫ��Ҳ������һ����ջ��*/

#include<stack>

template <typename T>
class QueueStack
{
public:
	QueueStack();
	~QueueStack();
public:
	int size() const;
	bool empty() const;
	T front() const;
	T back() const;
	void push(const T& data);
	void pop();
private:
	//��Ҫ��ȡ���ݵĶ�ջ
	stack<T>primary_;
	//������ջ
	stack<T>second_;
	//�����Ҫ�ʹ�Ҫ�Ķ�ջ
	void Clear();
};

template<typename T>
inline QueueStack<T>::QueueStack()
{
}

template<typename T>
inline QueueStack<T>::~QueueStack()
{
}

template<typename T>
inline int QueueStack<T>::size() const
{
	return primary_.size();
}

template<typename T>
inline bool QueueStack<T>::empty() const
{
	return primary_.empty();
}

template<typename T>
inline T QueueStack<T>::front() const
{
	if (empty())
		throw "ERROR:queue is empty.";
	return second_.top();
}

template<typename T>
inline T QueueStack<T>::back() const
{
	if (empty())
		throw "ERROR:queue is empty.";
	return primary_.top();
}

template<typename T>
inline void QueueStack<T>::push(const T& data)
/*��ջ����Ԫ���ڴ�Ҫջ��Ҷ��һ������ջ��������β*/
{
	if (empty())
	{
		primary_.push(data);
		while (!second_.empty())
			second_.pop();
		second_.push(data);
	}
	else
	{
		primary_.push(data);
	}
}

template<typename T>
inline void QueueStack<T>::pop()
/*��ջ*/
{
	if (empty())
		throw "ERROR:queue is empty, can not pop.";
	T back_data;
	T tmp_data;

	while (!second_.empty())
	{
		second_.pop();
	}
	//����Ҫջ�����ݵ����Ҫջ��
	while (!primary_.empty())
	{
		tmp_data = primary_.top();
		primary_.pop();
		second_.push(tmp_data);
	}
	//������Ҫջջ�����Ƕ��еĶ��׳�ջ
	second_.pop();
	//���ֻ��һ��Ԫ�ز��ҵ����˽���
	if (second_.empty())
		return;

	//�¶���Ԫ��
	back_data = second_.top();
	//����ԭ����ջ
	while (!second_.empty())
	{
		tmp_data = second_.top();
		primary_.push(tmp_data);
		second_.pop();
	}
	//���¶���Ԫ�ط����Ҫջ��
	second_.push(back_data);
}

template<typename T>
inline void QueueStack<T>::Clear()
{
	while (!primary_.empty())
		primary_.pop();
	while (!second_.empty())
		second_.pop();
}
