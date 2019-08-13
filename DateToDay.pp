/*
计算日期到天数转换

题目描述
	根据输入的日期，计算是这一年的第几天。。

详细描述：
	输入某年某月某日，判断这一天是这一年的第几天？。

 
输入描述:
	输入三行，分别是年，月，日
输出描述:
	成功:返回outDay输出计算后的第几天;
    失败:返回-1
	
示例1
输入
	2012
	12
	31
输出
	366

*/



#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v {0,31,59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int year, month, day;
    int sum;
    while(cin>>year>>month>>day){
        sum = 0;
        sum += v[month-1];
        sum += day;
        
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            sum +=1;
        
        cout << sum << endl;
    }
}

