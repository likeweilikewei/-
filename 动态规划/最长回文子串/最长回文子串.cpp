// 最长回文子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
	bool Judge(string s)
	{
		//判断是否是回文串
		int n = s.size();
		if (n == 0)
			return false;
		else if (n == 1)
			return true;
		for (int i = 0; i < n >> 1; i++)
		{
			if (s[i] != s[n - i - 1])
				return false;
		}
		return true;
	}

	string longestPalindrome(string s) {
		//暴力法 O(N^3)
		//     int n=s.size();
		//     if(n==0)
		//         return s;
		//     else if(n==1)
		//         return s;
		//     string max;
		//     for(int i=0;i<n;i++)
		//     {
		//         for(int j=i;j<n;j++)
		//         {
		//             string tmp=s.substr(i,j-i+1);
		//             if(Judge(tmp)&&tmp.size()>max.size())
		//                 max=tmp;
		//         }
		//     }
		//     return max;
		// }

		//上述方法每次都有大量重复判断回文串的计算，因此可以用动态规划优化，如果字符两边相等则是否是回文串和去掉两边的字符等价
		//申请一个二维数组d[i][j],存放下标i到j的字符是否是回文串1是0不是-1还没有计算
		// int n=s.size();
		// if(n==0)
		//     return "";
		// vector<vector<int>>d(n,vector<int>(n,1));
		// int max=0;
		// string result=s;
		// //从斜对角线开始向右上角移动
		// for(int j=0;j<n;j++)
		// {
		//     int a=0;
		//     int b=j;
		//     while(b<n)
		//     {
		//         if(a==b)
		//             d[a][b]=1;
		//         else if(s[a]==s[b]&&a+1<n&&b-1>=0)
		//             d[a][b]=d[a+1][b-1];
		//         else if(s[a]==s[b])
		//             d[a][b]=1;
		//         else
		//             d[a][b]=0;
		//         if(d[a][b]==1&&(b-a+1)>max)
		//         {
		//             max=b-a+1;
		//             result=s.substr(a,b-a+1);
		//         }
		//         a++;
		//         b++;
		//     }
		// }
		// return result;

		//因为同一时间只有每列的一个元素在使用，因此可以将二维空间 变为一维
		int n = s.size();
		if (n == 0)
			return "";
		//d[i]表示列下标为i时候的字符串，横坐标是某一个时刻的
		vector<int>d(n, 0);
		//保存上上一个斜线的内容
		vector<int>d1(n, 1);
		//暂存最新的上上一个斜线的，因为当前斜线是用到上上一个斜线的内容
		vector<int>d2(n, 1);
		int max = 0;
		string result = s;
		//从斜对角线开始向右上角移动
		for (int j = 0; j < n; j++)
		{
			int a = 0;
			int b = j;
			while (b < n)
			{
				if (a == b)
					d[b] = 1;
				else if (s[a] == s[b] && a + 1 < n && b - 1 >= 0)
					d[b] = d2[b - 1];
				else if (s[a] == s[b])
					d[b] = 1;
				else
					d[b] = 0;
				if (d[b] == 1 && (b - a + 1) > max)
				{
					max = b - a + 1;
					result = s.substr(a, b - a + 1);
				}
				a++;
				b++;
			}
			d2 = d1;
			d1 = d;
		}
		return result;
	}
};

int main()
{
	//0表示空字符null
	//char a = 0;
	//char b = 65;
	//cout << a << endl;
	//cout << b << endl;

	//求余时候带负号
	auto b = -11 % 10;
	cout << b << endl;

	//负数可以凑
	int c = 12;
	cout << -c << endl;

	long d = 12;
	//这是幂指数
	int e = pow(2,31) - 1;
	//这是异或
	int f = 2 ^ 3;
	cout << f << endl;
	cout << e << endl;
	if (d > e)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	int g = -21474836478;
	cout << g << endl;
	//long h = -g;
	//cout << h << endl;

	//Solution solution;
	//string result = solution.longestPalindrome("babad");
	//cout << result << endl;
}

