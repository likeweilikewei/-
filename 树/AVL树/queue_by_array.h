#pragma once
/*�����鶨�����,ʹ��ѭ�����У���front==backΪ�գ���(back+1)%max_size==front������
�ճ�һ��Ԫ�أ�������������δ��״̬��backָ����һ�����Բ���Ԫ�ص��±�
���������˾����������ڴ棬����Ԫ�ؿ���������ʹ��front����ָ��0
*/

template <typename T>
class Queue
{
public:
	Queue();
	~Queue();
	int size();
	bool empty();
	T front();
	T back();
	void push(T data);
	void pop();

//˽�нӿ�
private:
	bool IsFull();
	//����
	void IncreaseSize();
//˽������
private:
	T* queue_;
	int max_size_ = 10;
	//ÿ����������һ��
	const int& increase_size_ = max_size_;
	//ָ�����
	int front_ = 0;
	//ָ���β��һ���±�
	int back_ = 0;
};

template<typename T>
inline Queue<T>::Queue()
{
	queue_ = new T[max_size_];
	if (!queue_)
		throw "ERROR:new failed.";
}

template<typename T>
inline Queue<T>::~Queue()
{
	delete queue_;
	queue_ = nullptr;
}

template<typename T>
inline int Queue<T>::size()
{
	//��backС��front�����
	if (back_ < front_)
		return (back_ - front_) + max_size_;
	else
	{
		return back_ - front_;
	}
}

template<typename T>
inline bool Queue<T>::empty()
{
	return front_==back_;
}

template<typename T>
inline T Queue<T>::front()
/*�õ�����*/
{
	if (empty())
		throw "ERROR:queue is empty.";
	return queue_[front_];
}

template<typename T>
inline T Queue<T>::back()
/*�õ���βԪ��*/
{
	if (empty())
		throw "ERROR:queue is empty.";
	if (back_ == 0)
		return queue_[max_size_ - 1];
	else
		return queue_[back_-1];
}

template<typename T>
inline void Queue<T>::push(T data)
/*��ջ*/
{
	if (IsFull())
		IncreaseSize();
	queue_[back_] = data;
	back_ = (back_ + 1) % max_size_;
}

template<typename T>
inline void Queue<T>::pop()
/*��ջ*/
{
	if (empty())
		throw "ERROR:can not pop form empty queue.";
	front_ = (front_ + 1) % max_size_;
}

template<typename T>
inline bool Queue<T>::IsFull()
/*�ж��Ƿ�Ϊ�գ���ѭ����back��һ���±���front����*/
{
	if ((back_ + 1) % max_size_ == front_)
		return true;
	else
	{
		return false;
	}
}

template<typename T>
inline void Queue<T>::IncreaseSize()
/*����*/
{
	T* old_queue = queue_;
	int old_max_size = max_size_;
	max_size_ = max_size_ + increase_size_;
	queue_ = new T[max_size_];
	if (!queue_)
		throw "ERROR:new failed.";

	int i = front_;
	int k = 0;
	//����û��ѭ����front����ֱ�ӿ���
	if (back_ >= front_)
	{
		while (i<back_)
		{
			queue_[k] = old_queue[i];
			i++;
			k++;
		}
		front_ = 0;
		back_ = k;
	}
	//��ѭ����front�����ʱ����Ҫfront��ͷ
	else
	{
		//���ƽ�β����
		for (; i < old_max_size; i++)
		{
			queue_[k] = old_queue[i];
			k++;
		}
		//���ƿ�ͷ����
		for (i = 0; i < back_; i++)
		{
			queue_[k] = old_queue[i];
			k++;
		}
		front_ = 0;
		back_ = k;
	}
}
