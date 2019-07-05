/*
14.最长公共前缀
	编写一个函数来查找字符串数组中的最长公共前缀；如果不存在公共前缀，返回空字符串 ""。

示例 1:
	输入: ["flower","flow","flight"]
	输出: "fl"

示例 2:
	输入: ["dog","racecar","car"]
	输出: ""
	解释: 输入不存在公共前缀。

说明:所有输入只包含小写字母 a-z 。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ret = "";
		if (strs.empty())
			return ret; //输入为空，输出空ret
		string min = strs[0];
		for (int i = 1; i < strs.size(); ++i) //找到最短字符串
		{
			if (strs[i].size() < min.size())
				min = strs[i];
		}
		for (int j = 0; j < min.size(); ++j) //从第一个字符开始对比，若都一样，ret加上该字符，若不一样，返回答案；
		{
			for (int m = 0; m < strs.size(); ++m)
			{
				if (min[j] != strs[m][j])
					return ret;
			}
			ret= ret + min[j];
		}
		return ret ;
	}
};

int main()
{
	Solution S;
	vector<string>str = {"flower","flow","flight" };
	cout << S.longestCommonPrefix(str) << endl;
}