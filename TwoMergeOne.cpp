/*******************************************
 合并流
 
 合并两个内容流，第一个内容流每四个内容插入一个第二个内容流的数，合并完剩余的加在尾部
 
 例如：1 2 3 4 5 6 7 8 9
	   a b c 
	   1 2 3 4 a 5 6 7 8 b 9 c 
 *******************************************/
 
 #include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

string Func(const string &str1, const string &str2)
{
	string ret;
	int size = str1.size();
	int i = 0, j = 0;
	for (; i < size && j < str2.size(); ++i){
		ret.push_back(str1[i]);
		if ((i + 1) % 4 == 0)
			ret.push_back(str2[j++]);
	}
	if (j != str2.size())
		ret += str2.substr(j);
	if (i != str1.size())
		ret += str1.substr(i);

	return ret;
}


int main()
{
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2)){
		string s1, s2;
		for (auto i = 0; i < str1.size(); ++i){
			if (str1[i] != ' ')
				s1.push_back(str1[i]);
		}

		for (auto i = 0; i < str2.size(); ++i){
			if (str2[i] != ' ')
				s2.push_back(str2[i]);
		}

		str1 = Func(s1, s2);
		auto i = 0;
		for (; i < str1.size() - 1; ++i)
			cout << str1[i] << ' ';
		cout << str1[i] << endl;
	}

	system("pause");
	return 0;
}