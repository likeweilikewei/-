#pragma once
/*���������й����ջ,�����������У�һ����Ҫ���У�һ����Ҫ���У���Ҫ���ж�����Ϊջ��������ֱ�ӳ�ջ
��ջ��Ҫ���뵽���һ����*/

#include<queue>

template <typename T>
class StackQueue
{
public:
	StackQueue();
	~StackQueue();
public:
	bool empty() const;
	int size() const;
	T top() const;
	void push(const T& data);
	void pop();
private:
	//��Ҫ����
	queue<T>primary_;
	//��Ҫ����
	queue<T>second_;
};

template<typename T>
inline StackQueue<T>::StackQueue()
{
}

template<typename T>
inline StackQueue<T>::~StackQueue()
{
}

template<typename T>
inline bool StackQueue<T>::empty() const
{
	return primary_.empty();
}

template<typename T>
inline int StackQueue<T>::size() const
{
	return primary_.size();
}

template<typename T>
inline T StackQueue<T>::top() const
{
	return primary_.front();
}

template<typename T>
inline void StackQueue<T>::push(const T& data)
{
	while (!second_.empty())
		second_.pop();
	second_.push(data);
	T tmp_data;
	while (!primary_.empty())
	{
		tmp_data = primary_.front();
		second_.push(tmp_data);
		primary_.pop();
	}
	//���µ�����Ҫ������
	while (!second_.empty())
	{
		tmp_data = second_.front();
		second_.pop();
		primary_.push(tmp_data);
	}
}

template<typename T>
inline void StackQueue<T>::pop()
{
	primary_.pop();
}
