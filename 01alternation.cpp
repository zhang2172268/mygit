/*
01交替
时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 131072KB；其他语言 655360KB
题目描述：
给你一个长度为n的01串。现在想让你找出最长的01交替子串（子串可以不连续）比如：1010,0101是01交替的串，1101则不是。现在你可以把某一个连续的区间进行翻转，即0变1，1变0。问修改之后的最大01交替子串的长度是多少。

输入
输入第一行包含一个整数n （1 <= n <= 100000) 表示01串的长度。 第二行包含一个01串。



输出
输出一个数表示符合题意的子串长度


样例输入
8
10000011
样例输出
5
*/



#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
	int n;
	string s;
	cin >> n >> s;
	int ret = 1;
	for (int i = 1; i < n; i++)
	{
		if (s[i] != s[i - 1])
			ret += 1;
		
	}
		
	cout << min(ret + 2, n) << endl;
	//system("pause");
	return 0;
}