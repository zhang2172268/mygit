/*
计算字符串的距离

题目描述
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。
许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先
由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。

Ex：

字符串A:abcdefg
字符串B: abcdef

通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。

要求：
给定任意两个字符串，写出一个算法计算它们的编辑距离。


请实现如下接口

/*  功能：计算两个字符串的距离

 *  输入： 字符串A和字符串B

 *  输出：无

 *  返回：如果成功计算出字符串的距离，否则返回-1

 */

     public   static   int  calStringDistance (String charA, String  charB)

    {

        return  0;

    }  

 


输入描述:
	输入两个字符串

输出描述:
	得到计算结果

示例1
	输入abcdefg
		abcdef
	输出1
*/



#include <iostream>
#include <vector>
#include <string>
using namespace std;

int MinDistance(string str1, string str2)
{
    if(str1.empty() || str2.empty())
        return max(str1.size(), str2.size());
    int len1 = str1.size();
    int len2 = str2.size();
    
    vector<vector<int>> v(len1+1, vector<int>((len2+1), 0));
    for(int i = 0; i <= len1; ++i)
        v[i][0] = i;
    for(int j = 0; j <= len2; ++j)
        v[0][j] = j;
    
    for(int i = 1; i <= len1; ++i){
        for(int j = 1; j <= len2; ++j){
            if(str1[i-1] == str2[j-1]){
                v[i][j] = 1 + min(v[i][j-1], v[i-1][j]);
                v[i][j] = min(v[i][j], v[i-1][j-1]);
            }
            else{
                v[i][j] = 1 + min(v[i][j-1], v[i-1][j]);
                v[i][j] = min(v[i][j], 1 + v[i-1][j-1]);
            }
        }
    }
    return v[len1][len2];
}

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2)
        cout << MinDistance(str1, str2) << endl;
    
    return 0;
}