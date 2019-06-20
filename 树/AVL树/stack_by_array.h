#pragma once
/*用数组定义堆栈*/

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

//私有属性
private:
	T* stack_;
	int max_size_ = 10;
	//每次扩大容量一倍
	const int& increase_size_ = max_size_;
	//top-1是栈顶下标，栈在这里扩大
	int top_ = 0;
	//指向栈底
	int bottom_ = 0;

//私有接口
private:
	bool IsFull();
	//扩大容量
	void IncreaseSize();
};

template<typename T>
inline bool Stack<T>::IsFull()
/*判断是否为空*/
{
	return top_ - bottom_ == max_size_;
}

template<typename T>
inline void Stack<T>::IncreaseSize()
/*增大容量*/
{
	max_size_ = max_size_ + increase_size_;
	T* old_stack = stack_;
	stack_ = new T[max_size_];
	if (!stack_)
		throw "ERROR:new stack failed.";
	//拷贝数据
	int i = 0;
	for (i = 0; i < top_; ++i)
	{
		stack_[i] = old_stack[i];
	}

	//释放旧数组
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
/*元素进栈*/
{
	if (IsFull())
		IncreaseSize();
	stack_[top_++] = data;
}

template<typename T>
inline void Stack<T>::pop()
/*元素出栈*/
{
	if (empty())
		throw "ERROR:pop empty stack.";
	top_--;
}

template<typename T>
inline T Stack<T>::top()
/*取栈顶元素*/
{
	return stack_[top_-1];
}

template<typename T>
inline int Stack<T>::size()
/*得到栈中元素个数*/
{
	return top_-bottom_;
}

template<typename T>
inline bool Stack<T>::empty()
/*判断栈中元素是否为空*/
{
	return top_==bottom_;
}

