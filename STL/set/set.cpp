// set.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
begin()     　　 ,返回set容器的第一个元素

end() 　　　　 ,返回set容器的最后一个元素

clear()   　　     ,删除set容器中的所有的元素

empty() 　　　,判断set容器是否为空

max_size() 　 ,返回set容器可能包含的元素最大个数

size() 　　　　 ,返回当前set容器中的元素个数

rbegin　　　　 ,返回的值和end()相同

rend()　　　　 ,返回的值和rbegin()相同
*/

#include <iostream>
#include<set>

using namespace std;

template <typename T>
void show(const set<T>& sets)
/*显示set内容*/
{
	cout << endl;
	//这里的迭代器是常量迭代器，无法改变值
	//嵌套从属属性必须要typename类型，这个关键字用于指出模板声明中的非独立名称是类型名，而非变量名。
	for (typename set<T>::iterator iter = sets.begin(); iter != sets.end(); iter++)
	{
		cout << "set:" << *iter<< endl;
	}
}

struct Info
{
	string name_;
	double score_;
	bool operator<(const Info& other) const
	{
		//按sorce升序排列
		return score_ < other.score_;
	}
	Info(string name, double score) :name_(name), score_(score) {};
};

int main()
{
	set<int>set1;
	set1.insert(1);
	set1.insert(3);
	set1.insert(6);
	show(set1);
	set<int>set111 = set1;
	show(set111);
	cout << "-------------------" << endl;
	cout << "set1 size:" << set1.size() << endl;
	cout << "set1 max_size:" << set1.max_size() << endl;
	//判断数目其实就是判断是否有
	if (set1.count(1))
		cout << "has 1" << endl;
	else
		cout << "has not 1" << endl;

	//删除
	set<int>::iterator iter2 = set1.begin();
	//删除迭代器指向的元素
	set1.erase(iter2);
	show(set1);
	//删除指定范围的元素
	set1.insert(4);
	set1.insert(6);
	iter2 = set1.begin();
	show(set1);
	set<int>::iterator iter3 = set1.begin();
	iter3++;
	cout << *iter3 << endl;
	set1.erase(iter2, iter3);
	show(set1);
	//删除指定元素,如果不存在就没有反应
	set1.erase(6);
	show(set1);

	//find查找元素，找到就返回迭代器，没有找到就返回end迭代器
	if (set1.find(1) != set1.end())
		cout << "has 1" << endl;
	else
		cout << "has no 1" << endl;

	//insert插入元素，返回返回值是pair<set<int>::iterator,bool>，bool标志着插入是否成功，
	//而iterator代表插入的位置，若key_value已经在set中，则iterator表示的key_value在set中的位置。
	pair<set<int>::iterator, bool>result;
	cout << "---------------------" << endl;
	show(set1);
	set1.insert(6);
	//重复插入不会报错，但是是插入失败的
	result = set1.insert(6);
	cout << "result bool:" << result.second << endl;

	//条件查找
	/*
	lower_bound(key_value) ，算法返回一个非递减序列[first, last)中的第一个大于等于值val的位置
	upper_bound(key_value)，算法返回一个非递减序列[first, last)中第一个大于val的位置。
	*/
	set1.insert(2);
	set1.insert(234);
	show(set1);
	//没有则返回end
	if (set1.lower_bound(1000) == set1.end())
		cout << "no profit." << endl;
	//返回第一个大于等于6的元素
	cout << "lower bound " << *set1.lower_bound(6) << endl;
	//返回第一个大于6的元素
	cout << "upper bound " << *set1.upper_bound(6) << endl;
	if (set1.upper_bound(5) == set1.end())
		cout << "no profit" << endl;
	else
		cout << "yes:" << *set1.upper_bound(5) << endl;
	cout << "lower bound 10 is " << *set1.lower_bound(10) << endl;


	//对于自定义的结果可以将<操作符重载在自定义结果内
	set<Info>infos;
	Info info1("LI", 1.1);
	Info info2("hao", 2.2);
	Info info3("lala", 1.2);
	infos.insert(info1);
	infos.insert(info2);
	infos.insert(info3);
	for (set<Info>::iterator iter = infos.begin(); iter != infos.end(); iter++)
		cout <<"score "<< iter->score_ << endl;

	//set也有静态迭代器
	set<Info>::const_iterator iter0 = infos.begin();
	//逆向迭代器要用逆向迭代器
	set<Info>::reverse_iterator iter11 = infos.rbegin();
	set<Info>::reverse_iterator iter12 = infos.crbegin();
	//可以用非静态迭代器得到静态迭代器
	set<Info>::iterator iter13 = infos.cbegin();
	Info info4("ok", 6.6);
	//静态迭代器移动了也不能赋值
	/*
	 begin和end操作产生指向容器内第一个元素和最后一个元素的下一个位置的迭代器，如下所示。这两个迭代器通常用于标记包含容器中所有元素的迭代范围。

c.begin() 返回一个迭代器，它指向容器c的第一个元素

c.end() 返回一个迭代器，它指向容器c的最后一个元素的下一个位置

c.rbegin() 返回一个逆序迭代器，它指向容器c的最后一个元素

c.rend() 返回一个逆序迭代器，它指向容器c的第一个元素前面的位置

        上述每个操作都有两个不同的版本：一个是const成员，另一个是非const成员。
		这些操作返回什么类型取决于容器是否为const。如果容器不是const，
		则这些操作返回iterator或reverse_iterator类型。如果容器是const，
		则其返回类型要加上const_前缀，也就是const_iterator和const_reverse_iterator类型。

	*/
	//*(++iter13) = info4;
	cout << "score " << iter13->score_ << endl;
	cout << "score " << iter12->score_ << endl;
}

