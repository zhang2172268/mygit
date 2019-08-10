/*最长公共子串

题目描述
	查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
输入描述:
	输入两个字符串
输出描述:
	返回重复出现的字符
示例1
输入
	abcdefghijklmnop
	abcsafjklmnopqrstuvw
输出
	jklmnop

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str1, str2;
    while(cin >> str1 >> str2){
        if(str1.length() > str2.length())
            swap(str1, str2);
        
        int len1 = str1.length();
        int len2 = str2.length();
        
        int i, j, max = 0, start = 0;
        
        vector<vector<int>> MSC(len1+1, vector<int>(len2+1, 0));
        
        for(i = 1; i <= len1; ++i){
            for(j = 1; j <= len2; ++j){
                if(str1[i-1] == str2[j-1])
                    MSC[i][j] = MSC[i-1][j-1] +1;
                if(MSC[i][j] > max){
                    max = MSC[i][j];
                    start = i - max;
                }
            }
        }
        cout << str1.substr(start, max) << endl;
    }
    
    
    return 0;
}