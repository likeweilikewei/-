// map.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<map>

using namespace std;

template <typename  T, typename U>
void ShowMpa(const map<T, U>& maps)
{
	cout << endl;
	for (typename map<T, U>::const_iterator iter = maps.begin(); iter != maps.end(); iter++)
		cout<< "first:" << iter->first << " second:" << iter->second << endl;
}

int main()
{
    //map的声明
	map<int, string>name;
	//也可以用{}的形式申明和初始化
	map<string, string>keys = { {"name","likewei"},{"age","eleven"} };
	//遍历
	map<string, string>::const_iterator iter;
	for (iter = keys.begin(); iter != keys.end(); iter++)
		cout << "first:" << iter->first << " second:" << (*iter).second << endl;

	//插入动作
	//可以用[]数组的形式直接插入，如果有的话就覆盖
	name[2] = "xiamei";
	ShowMpa(name);
	name[2] = "likew";
	ShowMpa(name);
	//用insert插入,insert不会覆盖，只会插入失败
	//直接用pair插入
	name.insert(pair<int, string>(3, "xiamei"));
	ShowMpa(name);
	//利用insert返回迭代器和标志判断是否插入才成功
	pair<map<int,string>::iterator,bool>result;
	result = name.insert(pair<int, string>(3, "like"));
	cout << "result first->second:" << result.first->second << " second:"<<result.second << endl;
	//在迭代器指针指向的位置前插入pair,map是有序的，无论哪个位置插入都一样
	cout << endl;
	map<int, string>::iterator iters=name.begin();
	map<int, string>::iterator ends = name.end();
	name.insert(iters, pair<int, string>(7, "yes"));
	ShowMpa(name);
	name.insert(iters, pair<int, string>(22, "ok"));
	name.insert(iters, pair<int, string>(21, "no"));
	ShowMpa(name);
	name.insert(ends, pair<int, string>(15, "jsl"));
	ShowMpa(name);
	//insert插入指定范围的数据，注意看后面范围是不包括的
	map<int, string>new_map;
	//find返回查找到的元素的迭代器，如果没有就返回end，也就是说没有就全插入
	new_map.insert(iters, name.find(15));
	ShowMpa(new_map);
	//insert多值插入也可以用初始列表的形式
	new_map.insert({ { 1,"hello" }, { 0,"world" } });
	ShowMpa(new_map);

	//取值，有at和【】,at会做会做下标检查，后者不会，只会打印结果为空，不占位置
	cout << new_map.at(1) << endl;
	cout << new_map[1] <<"yes"<< endl;
	cout << new_map[11] << endl;
	new_map[11] = "11";
	cout << "ss" << endl;
	//出错
	//cout << new_map.at(1111) << endl;
	cout << "aa" << endl;
	//这个插入会出错
	new_map.at(11) = "111";
	//at可以赋值
	new_map.at(1) = "111";
	cout << new_map[1] << endl;

	////判断有没有不能通过直接if(aa[x])，因为不一定是int
	map<int, int>aa;
	aa[1] = 2;
	if (aa[1]!=0)
		cout << "yes" << endl;
	//判断map是否有某个数据可以用count计数或者find
	if (aa.count(1) != 0)
		cout << "yesss" << endl;
	if (aa.find(1) != aa.end())
		cout << "ok" << endl;

	//容量查询
	cout << "aa empty:" << aa.empty() << endl;
	//查询键值对数目
	cout << "aa size:" << aa.size() << endl;
	// 查询map所能包含的最大键值对数量，和系统和应用库有关。
	// 此外，这并不意味着用户一定可以存这么多，很可能还没达到就已经开辟内存失败了
	cout << "aa max_size:" << aa.max_size() << endl;
	//查询关键字为key的的元素的个数
	cout << "aa 1 count:" << aa.count(1) << endl;

	//迭代器
	/*
	共有八个获取迭代器的函数：* begin, end, rbegin,rend* 以及对应的 * cbegin, cend, crbegin,crend*。

	二者的区别在于，后者一定返回 const_iterator，而前者则根据map的类型返回iterator 或者 const_iterator。const情况下，不允许对值进行修改。如下面代码所示：
	*/
	map<int, int>mmap;
	const map<int, int> const_map = { {1,2},{3,4} };
	mmap.insert(pair<int, int>(1, 22));
	mmap.insert(pair<int,int>(2,33));
	//常量const修饰map出的迭代器和const_iterator一样，下面如果用map修饰就不能对数据进行修改了
	map<int, int>::iterator iterss;
	map<int, int>::const_iterator citer;
	iterss = mmap.begin();
	cout << "first:" << iterss->first << " second:" << iterss->second << endl;
	//普通迭代器可以修改键值，但是不能修改键，键是常量不可修改
	iterss->second = 235;
	citer = mmap.cbegin();
	//直接编译错误
	//citer->second = 345;
	//常量map必须用静态迭代器
	const map<int, int>::const_iterator const_map_iter= const_map.begin();
	cout << "const map iter:" << const_map_iter->first << "  second:" << const_map_iter->second << endl;
	ShowMpa(mmap);


	//删除
	//删除迭代器指定键值对，并返回下一个元素迭代器
	iterss=mmap.erase(iterss);
	cout << "first:" << iterss->first << " second:" << iterss->second << endl;
	ShowMpa(mmap);
	mmap.insert(pair<int, int>(3, 22));
	mmap.insert(pair<int, int>(4, 33));
	mmap.insert(pair<int, int>(5, 22));
	mmap.insert(pair<int, int>(6, 33));
	//删除指定范围的迭代器元素
	iterss = mmap.begin();
	ShowMpa(mmap);
	map<int, int>::iterator other = iterss;
	//删除左闭右开的迭代器元素
	mmap.erase(iterss, ++other);
	ShowMpa(mmap);
	//删除指定关键字对应元素
	mmap.erase(6);
	ShowMpa(mmap);
	//清空map
	//mmap.clear();

	//交换两个map内容
	map<int, int>seconds = { {123,42},{21,45} };
	mmap.swap(seconds);
	ShowMpa(mmap);


	//比较关键字先后
	mmap.insert(pair<int, int>(3, 22));
	mmap.insert(pair<int, int>(4, 33));
	mmap.insert(pair<int, int>(5, 22));
	mmap.insert(pair<int, int>(6, 33));
	map<int, int>::key_compare mycmp = mmap.key_comp();
	//返回false
	cout << "compare:" << mycmp(6, 4) << endl;


	//查找，如果有就指向元素迭代器，如果没有就返回指向end的迭代器
	iterss = mmap.find(4);
	if (iterss != mmap.end())
		cout << "first:" << iterss->first << " second:" << iterss->second << endl;
	else
		cout << "no" << endl;

	seconds[7] = 1242;
	ShowMpa(seconds);
	ShowMpa(mmap);
	//注意 对于==运算符, 只有键值对以及顺序完全相等才算成立。
	//操作符会依次比较每个关键字
	if (seconds > mmap)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	//map没有capacity
}

