#include <iostream>
using namespace std;

double getAverage(int* arr, int size); //形式参数是一个指针：
double getAverage(int arr[1]); // 重载函数，形式参数是一个已定义大小的数组：
double getAverage2(int arr[]); // 不可重载，形式参数是一个未定义大小的数组：

int main(int argc, char const* argv[])
{
	// 带有 5 个元素的整型数组
	int balance[5] = { 1000, 2, 3, 17, 50 };
	int* pt1 = balance;
	// 分别计算数组元素个数，以及整型指针的字节数
	size_t balance_size = sizeof(balance) / sizeof(int);
	size_t pt1_size = sizeof(pt1);

	double avg, avg2, avg3;

	cout << "array size : " << balance_size << endl;
	cout << "pt1_size : " << pt1_size << endl;

	avg = getAverage(balance, 5);
	avg2 = getAverage(balance);
	avg3 = getAverage2(balance);

	// 输出返回值
	cout << "方法1平均值是：" << avg << endl;
	cout << "方法2平均值是：" << avg << endl;
	cout << "方法3平均值是：" << avg << endl;
	return 0;
}

double getAverage(int* arr, int size)
{
	int i, sum = 0;
	double avg;
	// 打印第一个形参的字节数
	cout << "Inside getAverage sizeof(arr) = " << sizeof(arr) << endl;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = double(sum) / size;
	return avg;
}

double getAverage(int arr[1])
{
	int i, sum = 0, size = 5;
	double avg;
	// 打印第一个形参的字节数
	cout << "arr:" << *arr << endl;;
	cout << "arr+1:" << arr[1] << endl;
	cout << "Inside getAverage sizeof(arr) = " << sizeof(arr) << endl;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = double(sum) / size;
	return avg;
}

double getAverage2(int arr[])
{
	int i, sum = 0, size = 5;
	double avg;
	// 打印第一个形参的字节数
	cout << "Inside getAverage sizeof(arr) = " << sizeof(arr) << endl;
	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = double(sum) / size;
	return avg;
}
