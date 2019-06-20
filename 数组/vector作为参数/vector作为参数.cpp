// vector作为参数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<string>

using namespace std;

template <typename T>
void test_vector(vector<T> objs)
{
	//cout << objs.size()<<"yes";
	//vector无法直接输出
	cout << "objs:" << objs[0] << endl;
	cout << "&obj:" << &objs << endl;
	//由于vector传过来不是指针，因此不能解析
	//cout << "*obj:" << *objs << endl;
	//也不能运用加减法
	//cout << "obj+1:" << objs + 1 << endl;
	//cout << "&(obj+1):" << &(objs + 1) << endl;
	//cout << "*(obj+1):" << *(objs + 1) << end;
}

vector<int> twoSum(vector<int>& nums, int target) {
	/*
	gcc中在循环外面也要有返回，不然报错
	*/
	vector<int>result;
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{

				result.push_back(i);
				result.push_back(j);

			}
		}
	}
	return result;
}

int main()
{
	/*
	int size() const:返回向量中元素的个数
	int capacity() const:返回当前向量张红所能容纳的最大元素值
	int max_size() const:返回最大可允许的vector元素数量值
	*/
	vector<int>a;
	cout << "a.size:" << a.size() << endl;
	cout << "a.capacity:" << a.capacity() << endl;
	cout << "a.max_size:" << a.max_size() << endl;
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "a.capacity:" << a.capacity() << endl;
		a.push_back(i);
	}
	cout << a[1] << endl;
	cout << a[0] << endl;
	test_vector(a);
	cout << "a.size:" << a.size() << endl;
	cout << "a.capacity:" << a.capacity() << endl;
	cout << "a.max_size:" << a.max_size() << endl;
	cout << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "a.capacity:" << a.capacity() << endl;
		a.push_back(i);
	}

	vector<int>b(10, 2);
	b.push_back(3);
	b.push_back(4);
	//得到编号位置的数据
	cout << b.at(3);

	auto result2 = twoSum(b, 5);
	for (int i = 0; i < result2.size(); i++)
		cout << "result2:" << result2[i] << endl;
}

