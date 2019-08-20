/* 把数组排成最小的数
 
 问题描述：输入一个正整数数组，将它们连接起来排成一个数，输出能排出的所有数字中最小的一个。
 例如输入数组{32,  321}，则输出这两个能排成的最小数字32132。请给出解决问题的算法，并证明该算法。
 
 */
 
 
 #include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


string PrintMinNum(vector<int> num)
{
	vector<string> v2;
	for (auto& e : num)
		v2.push_back(to_string(e));
	sort(v2.begin(), v2.end(), [](string& s1, string& s2) {return s1 + s2 < s2 + s1; });
	string ret = "";
	for (auto& e : v2)
		ret += e;
	return ret;
}


int StrToInt(string str)
{

	stringstream tmp(str);
	int ret;
	tmp >> ret;

	return ret;
}

int main()
{
	string str;

	while (cin >> str)
	{
		vector<int> buf;
		string tmp;

		int j = 0;
		for (auto i = 0; i < str.size(); ++i)
		{
			tmp.push_back(str[i]);
			if (str[i] == ',')
			{
				buf.push_back(StrToInt(tmp));
				tmp.clear();
			}
		}
		if (!tmp.empty())
			buf.push_back(StrToInt(tmp));

		cout << PrintMinNum(buf) << endl;

	}

	return 0;
}