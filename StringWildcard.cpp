/*字符串通配符

题目描述
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、
		  正则表达式等领域。现要求各位实现字符串通配符的算法。

要求：
实现如下2个通配符：
*：匹配0个或以上的字符（字符由英文字母和数字0-9组成，不区分大小写。下同）
？：匹配1个字符


输入：
	通配符表达式；
	一组字符串。

输出：
	返回匹配的结果，正确输出true，错误输出false

输入描述:
	先输入一个带有通配符的字符串，再输入一个需要匹配的字符串

输出描述:
	返回匹配的结果，正确输出true，错误输出false

示例1
输入
te?t*.*
txt12.xls

输出
false

*/


#include <iostream>
#include <string>
using namespace std;

bool match(const char* pattern, const char *str)
{
    if(*pattern == '\0' && *str == '\0')
        return true;
    if(*pattern == '\0' || *str == '\0')
        return false;
    
    if(*pattern == '?')
        return match(pattern+1, str+1);
    else if(*pattern == '*')
        return match(pattern+1, str) || match(pattern+1, str+1) || match(pattern, str+1);
    else if(*pattern == *str)
        return match(pattern+1, str+1);

    return false;
}

int main()
{
    string pattern, str;
    while(cin>>pattern>>str){
        bool ret = match(pattern.c_str(), str.c_str());
        if(ret)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}