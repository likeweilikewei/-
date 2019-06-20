// sizeof.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>

using namespace std;

/*
第一种情况：　　　　　　　　 第二种情况：　　　　　　　　　　第三种情况　　　　　　　　　　　　第四种情况：
class a　　　　　　　　　　　class a　　　　　　　　　　　　  class a　　　　　　　　　　　　　　class a
{　　　　　　　　　　　　　 {　　　　　　　　　　　　　　　 {　　　　　　　　　　　　　　　　　{
	virtual void func();　　　　　　virtual void func();　　　　　　　virtual void func();　　　　　　　　virtual void func();
};　　　　　　　　　　　　　 };　　　　　　　　　　　　　　　　　 char x;　　　　　　　　　　　　　　char x;
class b:public virtual a　　　class b :public a　　　　　　　    };　　　　　　　　　　　　　　　　};
{　　　　　　　　　　　　　　{　　　　　　　　　　　　　　 　class b:public virtual a　　　　　 class b:public a
	virtual void foo();　　　　　　  virtual void foo();　　　　　{　　　　　　　　　　　　　　　　 {
};　　　　　　　　　　　　　 };　　　　　　　　　　　　　　　　　　virtual void foo();　　　　　　　　virtual void foo();
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　};　　　　　　　　　　　　　　　　};



大可不必纠结得到的结果和博主的不一样，不同操作系统，不同位数，不同编译器结果基本都不一样，博主的可以通过vs 提供的d1reportSingleClassLayout[classname]去查看内存结构，一般基类都没问题（64位系统指针占8个字节），对于子类：
第一个：vfptr(b:foo)+vbptr+vfptr(a:func)=12
第二个：vfptr(a:func, b:foo)=4
第三个：vfptr(b:foo)+vbptr+vfptr(a:func)+x(对齐为四个字节)=16
第四个：vfptr(a:func, b:foo)+x(对齐为四个字节)=8
这里没有类之间的函数覆盖，如果有会更麻烦一点。
*/

class A1
{
	virtual void func();
};

class B1:public virtual A1
{
	virtual void foo();
};

class A2
{
	virtual void func();
};

class B2 :public A2
{
	virtual void foo();
};

class A3
{
	virtual void func();
	char x;
};

class B3 :public A3
{
	virtual void foo();
};

class A4
{
	virtual void func();
	char x;
};

class B4 :virtual public A4
{
	virtual void foo();
};

class BTest
{
	float t;
	char p;
	int adf[3];
};

struct CTest
{
	float t;
	char p;
	int adf[3];
};

struct DTest
{
	int a;
	int b;
	char p;
	char adf[8];
};


class Animal
{
public:
	//如果去除这里的virtual，所有派生类都会调用这个方法
	virtual void eat() const
	{
		cout << "I eat like a generic animal." << endl;
	}
	virtual ~Animal() {}
};

class Wolf :public Animal
{
public:
	void eat() const
	{
		cout << "I eat like a wolf." << endl;
	}
};

class Fish :public Animal
{
public:
	void eat() const
	{
		cout << "I eat like a fish." << endl;
	}
private:
	char b = '0';
};

class OtherAnimal :public Animal
{
};

class A
{};

class B
{
public:
	char b;
};

class C
{
public:
	int a;
	static int b;
	C();
	~C();
};

class D
{
public:
	int a;
	int b;
	virtual void eat() { cout << "I eat like a generic animal." << endl; };
	~D();
};

class E:public D
{
public:
	//如果去除这里的virtual，所有派生类都会调用这个方法
	void eat() const
	{
		cout << "I eat like a generic animal." << endl;
	}
	int d;
	~E() {}
};

class F :public E
{
	virtual void eat2() const
	{
		cout << "I eat like a generic animal." << endl;
	}
	virtual void eat3() const
	{
		cout << "I eat like a generic animal." << endl;
	}
	virtual void eat4() const
	{
		cout << "I eat like a generic animal." << endl;
	}
	~F();
};

int test(char var[])
{
	return sizeof(var);
}

int main()
{
	/*
	string：string是STL当中的一个容器，对其进行了封装，所以操作起来非常方便。

char*：char *是一个指针，可以指向一个字符串数组，至于这个数组可以在栈上分配，也可以在堆上分配，堆得话就要你手动释放了。

2、区别：

string的内存管理是由系统处理，除非系统内存池用完，不然不会出现这种内存问题。
char *的内存管理由用户自己处理，很容易出现内存不足的问题。

当我们要存一个串，但是不知道其他需要多少内存时， 用string来处理就最好不过了。
当你知道了存储的内存的时候，可以用char *，但是不如用string的好，用指针总会有
隐患。

用string还可以使用各种成员函数来处理串的每一个字符，方便处理。
用char *处理串，就不如string的方便了，没有相应的函数来直接调用，而是要自己编
写函数来完成串的处理，而且处理过程中用指针还很容易出现内存问题。

char *s="string"的内容是不可以改的；char s[10]="string"的内容是可以改的

3、注意：

当我们定义了一个string，就不能用scanf("%s",s)和printf("%s",s)输入输出。主要是因为%s要求后面是对象的首地址

4、转化：

当 string 直接转化成 const char *时，可以通过两个函数c_str()，data成员函数
	*/
    
	//char*字符数组的几种创建方法和对应的大小
	//指针型、不指定数组大小
	const char* s1 = "0123456789";
	//得到数组
	cout << "s1:" << s1 << endl;
	//得到第一个字符
	cout << "*s1:" << *s1 << endl;
	//指针大小四个字节
	cout << "sizeof s1:" << sizeof(s1) << endl;
	//第一个字符一个字节
	cout << "sizeof *s1:" << sizeof(*s1) << endl;
	//strlen计算的长度还是10
	cout << "len of s1:" << strlen(s1) << endl;
	cout << endl;

	//非指针型，不指定数组大小
	char s2[] = "0123456789";
	//输出完整数组
	cout << "s2:" << s2 << endl;
	//得到第一个字符，c++中传递数组永远都是传递数组的指针
	cout << "*s2:" << *s2 << endl;
	//字符数组11个字节（加上'\0'结尾）
	cout << "sizeof s2:" << sizeof(s2) << endl;
	//第一个字符一个字节
	cout << "sizeof *s2:" << sizeof(*s2) << endl;
	//strlen计算的长度还是10
	cout << "len of s2:" << strlen(s2) << endl;
	cout << endl;

	//非指针型，预分配大小
	char s3[100] = "0123456789";
	//得到数组
	cout << "s3:" << s3 << endl;
	//得到第一个字符
	cout << "*s3:" << *s3 << endl;
	//100个字节，包括'\0'
	cout << "sizeof s3:" << sizeof(s3) << endl;
	//第一个字符一个字节
	cout << "sizeof *s3:" << sizeof(*s3) << endl;
	cout << endl;

	//c++中的string创建，string是字符序列,string对象不能用*取得内容
	string s4("0123456789");
	//得到字符序列
	cout << "s4:" << s4 << endl;
	//28个字节		
	cout << "sizeof s4:" << sizeof(s4) << endl;
	//大小为10
	cout << "len of s4:" << s4.size() << endl;
	cout << endl;

	string s5="0123456789";
	//得到字符序列
	cout << "s5:" << s5 << endl;
	//28个字节
	cout << "sizeof s5:" << sizeof(s5) << endl;
	//大小为10
	cout << "len of s5:" << s5.size() << endl;
	cout << endl;

	//把对象初始化为10个 '0'字符组成的串
	string s6(10,'0');
	//得到字符序列
	cout << "s6:" << s6 << endl;
	//28个字节
	cout << "sizeof s6:" << sizeof(s6) << endl;
	//大小为10
	cout << "len of s6:" << s6.size() << endl;
	cout << endl;

	//列表初始化字符数组
	char s7[] = {'0','1','2','3', '4','5', '6','7', '8','9'};
	//得到数组，由于没有包含空字符，结尾可能输出一些杂乱字符
	cout << "s7:" << s7 << endl;
	//得到第一个字符
	cout << "*s7:" << *s7 << endl;
	//10个字节，不包括'\0'
	cout << "sizeof s7:" << sizeof(s7) << endl;
	//第一个字符一个字节
	cout << "sizeof *s7:" << sizeof(*s7) << endl;
	//大小为10
	cout << "len of s6:" << strlen(s7) << endl;
	cout << endl;

	//列表初始化string对象的数组
	string s8[] = { "trends","micro","soft" };
	//得到指向string的数组的指针
	cout << "s8:" << s8 << endl;
	//得到第一个元素
	cout << "*s8:" << *s8 << endl;
	//84个字节，每个string对象占28个字节
	cout << "sizeof s8:" << sizeof(s8) << endl;
	//每个string对象占28个字节
	cout << "sizeof *s8:" << sizeof(*s8) << endl;
	//大小为28
	cout << "sizeof s8[0]:" << sizeof(s8[0]) << endl;
	cout << "sizeof s8[2]:" << sizeof(s8[2]) << endl;
	cout << "len of s8:" << sizeof(s8)/sizeof(s8[0]) << endl;
	cout << endl;

	//列表初始化字符数组，带空字符
	char s9[] = { '0','1','2','3', '4','5', '6','7', '8','9','\0'};
	//得到数组，没有杂乱字符
	cout << "s9:" << s9 << endl;
	//得到第一个字符
	cout << "*s9:" << *s9 << endl;
	//11个字节，包括'\0'
	cout << "sizeof s9:" << sizeof(s9) << endl;
	//第一个字符一个字节
	cout << "sizeof *s9:" << sizeof(*s9) << endl;
	//strlen专门对字符数组提供了一个strlen函数获取长度，长度依然是10，空字符没有计入长度
	cout << "len of s6:" << strlen(s9) << endl;
	cout << endl;

	//一个先定义大小的指向字符串数组的指针
	string* s10 = new string[2];
	s10[0] = "li";
	s10[1] = "ke";
	//string数组得到的都是指针
	//得到指向第一个string的指针的值
	cout <<"s10:"<< s10 << endl;
	//得到第一个string对象
	cout << "*s10:" << *s10 << endl;
	//指针大小为4个字节，不同编译器不一样
	cout << "sizeof s10:" << sizeof(s10) << endl;
	//string大小为28个字节，不同编译器不一样
	cout << "sizeof *s10:" << sizeof(*s10) << endl;
	cout << "sizeof string:" << sizeof(string) << endl;
	cout << endl;

	//类的大小
	cout << "size of Animal:" << sizeof(Animal) << endl;
	cout << "size of Wolf:" << sizeof(Wolf) << endl;
	cout << "size of Fish:" << sizeof(Fish) << endl;
	cout << "size of OtherAnimal:" << sizeof(OtherAnimal) << endl;
	//空类一个字节
	cout << "size of A:" << sizeof(A) << endl;
	//只有一个char变量的类，一个字节
	cout << "size of B:" << sizeof(B) << endl;
	//static静态变量存放在全局数据区中，sizeof计算栈中分配的大小，不会计算在内，因此只有一个int变量，4个字节
	cout << "size of C:" << sizeof(C) << endl;
	//有数据成员的时候按数据成员算，有虚函数时候加上虚函数,12字节
	cout << "size of D:" << sizeof(D) << endl;
	//虚函数（多个算一个）占4个字节，16字节，虚继承涉及虚表，也就是虚指针 0
	cout << "size of E:" << sizeof(E) << endl;
	//派生类大小在基类大小上加，16字节
	cout << "size of F:" << sizeof(F) << endl;
	cout << endl;

	//数组当参数传递的时候退化为指针为四个字节
	char var[10];
	int restult = test(var);
	cout << "result:" << restult << endl;
	cout << endl;

	//17个字节，内存对齐选择4的倍数为20字节
	cout << "size of BTest:" << sizeof(BTest) << endl;
	cout << endl;

	//struct和class一样
	cout << "size of CTest:" << sizeof(CTest) << endl;
	cout << endl;

	//类的字节数等于最大类型的整数倍，数组算元素的类型
	cout << "size of DTest:" << sizeof(DTest) << endl;
	cout << endl;


	cout << endl << endl;
	cout << sizeof(A1) << " "<<sizeof(B1) << endl;
	cout << sizeof(A2) << " " << sizeof(B2) << endl;
	cout << sizeof(A3) << " " << sizeof(B3) << endl;
	cout << sizeof(A4) << " " << sizeof(B4) << endl;


	//内置类型的在32位编译器中的大小
	cout << "size of bool:" << sizeof(bool) << endl;
	cout << "size of char:" << sizeof(char) << endl;
	cout << "size of wchar_t:" << sizeof(wchar_t) << endl;
	cout << "size of char16_t:" << sizeof(char16_t) << endl;
	cout << "size of char32_t:" << sizeof(char32_t) << endl;
	cout << "size of short:" << sizeof(short) << endl;
	cout << "size of int:" << sizeof(int) << endl;
	cout << "size of long:" << sizeof(long) << endl;
	cout << "size of long long:" << sizeof(long long) << endl;
	cout << "size of float:" << sizeof(float) << endl;
	cout << "size of double:" << sizeof(double) << endl;
	cout << "size of long double:" << sizeof(long double) << endl;
	/*
	size of bool:1
size of char:1
size of wchar_t:2
size of char16_t:2
size of char32_t:4
size of short:2
size of int:4
size of long:4
size of long long:8
size of float:4
size of double:8
size of long double:8
	*/
}


