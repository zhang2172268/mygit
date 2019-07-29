/*公共字串计算

题目描述
题目标题：

计算两个字符串的最大公共字串的长度，字符不区分大小写

详细描述：

接口说明

原型：

int getCommonStrLength(char * pFirstStr, char * pSecondStr);

输入参数：

     char * pFirstStr //第一个字符串

     char * pSecondStr//第二个字符串
 

输入描述:
	输入两个字符串

输出描述:
	输出一个整数

示例1
	输入asdfas werasdfaswer
	输出6
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    while(cin>>str1>>str2){
        int max = 0;
        vector<vector<int>> dp(str1.length(), vector<int> (str2.length(), 0));
        for(int i = 0; i < str1.length(); ++i){
            for(int j = 0; j < str2.length(); ++j){
                if(str1[i] == str2[j]){
                    if(i >= 1 && j >= 1)
                        dp[i][j] = dp[i-1][j-1] +1;
                    else
                        dp[i][j] = 1;
                }
                if(dp[i][j] > max)
                    max = dp[i][j];
            }
        }
        
        cout << max <<endl;
    }
    return 0;
}