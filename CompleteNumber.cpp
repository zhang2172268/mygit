/*完全数计算

题目描述：
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
返回n以内完全数的个数。 异常情况返回-1



 * 

 *  完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。

 *  它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。

 *  例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。

 * 

 *  给定函数count(int n),用于计算n以内(含n)完全数的个数

 * @param n  计算范围, 0 < n <= 500000

 * @return n 以内完全数的个数, 异常情况返回-1

 * 

 

public   static   int  count( int  n)


输入描述:
	输入一个数字
输出描述:
	输出完全数的个数

示例1
	输入1000
	输出3
	
*/


#include <iostream>
#include <algorithm>
using namespace std;

int count (int n)
{
    int cnt = 0;
    
    if(n < 0 || n > 500000)
        return -1;
    else{
        for(int i =2; i <= n; ++i){
            int sum = 0;
            for(int j = 2; j <= sqrt(i); ++j){
                if(i % j == 0){
                    if(i / j == j)
                        sum += j;
                    else 
                        sum += j + (i/j);
                }
            }
            if(sum+1 == i)
                cnt++;
        }
        return cnt;
    }
}

int main()
{
    int n;
    while(cin >> n)
        cout << count(n) << endl;
    return 0;
}