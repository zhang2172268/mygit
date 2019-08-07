/*超长正整数相加

题目描述
	请设计一个算法完成两个超长正整数的加法。

接口说明
 请设计一个算法完成两个超长正整数的加法。
 输入参数：
 String addend：加数
 String augend：被加数
 返回值：加法结果

 public String AddLongInteger(String addend, String augend)
 {
     在这里实现功能
  

  return null;     
 }


输入描述:
	输入两个字符串数字
输出描述:
	输出相加后的结果，string型

示例1
输入
	99999999999999999999999999999999999999999999999999
	1
输出	
	100000000000000000000000000000000000000000000000000
	
*/


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addstring(string s1, string s2)
{
    int i = s1.size()-1;
    int j = s2.size()-1;
    int car = 0;
    string ret = " ";
    while(i>=0 || j>=0){
        if(i>=0)
            car += s1[i] - '0';
        if(j>=0)
            car += s2[j] - '0';
        
        ret +=(char)(car % 10 + '0');
        
        car /= 10;
        i--;
        j--;
    }
    if(car==1)
        ret += '1';
    reverse(ret.begin(), ret.end());
    return ret;
}


int main()
{
    string s1, s2;
    while(cin>>s1>>s2)
        cout << addstring(s1, s2) << endl;
    return 0;
}