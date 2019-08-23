
/*****************************************************************
 字符串的描述
 题目描述:
	输入一个字符串,要求输出字符串中字符所有的排列,例如输入"abc",得到"abc","acb","bca","bac","cab","cba"
 ****************************************************************/
#include <iostream>
#include <string>
using namespace std;

void bubbleSort(string str, int begin, int len)
{
	for (int i = 0; i < len; ++i){
		for (int j = i + 1; j < len; ++j){
			if (str[i] > str[j])
				swap(str[i], str[j]);
		}
	}
}

void Permulation(string str, int k, int len)
{
	int i;
	if (len == k){
		for (i = 0; i < len; ++i)
			cout << str[i];
		cout << endl;
	}
	else{
		for (i = k; i < len; ++i){
			if (k != i && str[k] == str[i])
				continue;
			swap(str[k], str[i]);
			bubbleSort(str, k + 1,len);
			Permulation(str, k + 1, len);
			bubbleSort(str, k + 1, len);
		}
	}
}

int main()
{
	string str;
	while (cin >> str){
		int len = str.size();
		bubbleSort(str, 0, len);
		Permulation(str, 0, len);
	}


	system("pause");
	return 0;
}