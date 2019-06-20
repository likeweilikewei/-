#pragma once
/*用数组定义队列,使用循环队列，当front==back为空，当(back+1)%max_size==front是满，
空出一个元素，用来区分满和未满状态，back指向下一个可以插入元素的下标
当数组满了就重新申请内存，并将元素拷贝进来，使得front重新指向0
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

//私有接口
private:
	bool IsFull();
	//扩容
	void IncreaseSize();
//私有属性
private:
	T* queue_;
	int max_size_ = 10;
	//每次扩大容量一倍
	const int& increase_size_ = max_size_;
	//指向队首
	int front_ = 0;
	//指向队尾后一个下标
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
	//当back小于front的情况
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
/*得到队首*/
{
	if (empty())
		throw "ERROR:queue is empty.";
	return queue_[front_];
}

template<typename T>
inline T Queue<T>::back()
/*得到队尾元素*/
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
/*进栈*/
{
	if (IsFull())
		IncreaseSize();
	queue_[back_] = data;
	back_ = (back_ + 1) % max_size_;
}

template<typename T>
inline void Queue<T>::pop()
/*出栈*/
{
	if (empty())
		throw "ERROR:can not pop form empty queue.";
	front_ = (front_ + 1) % max_size_;
}

template<typename T>
inline bool Queue<T>::IsFull()
/*判断是否为空，当循环着back下一个下标是front则满*/
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
/*扩容*/
{
	T* old_queue = queue_;
	int old_max_size = max_size_;
	max_size_ = max_size_ + increase_size_;
	queue_ = new T[max_size_];
	if (!queue_)
		throw "ERROR:new failed.";

	int i = front_;
	int k = 0;
	//当还没有循环到front后面直接拷贝
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
	//当循环到front后面的时候，需要front掉头
	else
	{
		//复制结尾部分
		for (; i < old_max_size; i++)
		{
			queue_[k] = old_queue[i];
			k++;
		}
		//复制开头部分
		for (i = 0; i < back_; i++)
		{
			queue_[k] = old_queue[i];
			k++;
		}
		front_ = 0;
		back_ = k;
	}
}
