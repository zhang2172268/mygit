/*
查找组成一个偶数最接近的两个素数

题目描述：
	任意一个（大于2）都可以由2两个素数组成，组成偶数的2个素数由很多中情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
	
输入描述：输入一个偶数
输出描述：输出两个个素数

示例：
	输入20
	输出7
	    13
		
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int num)
{
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int num;
    int i;
    while(cin>>num){
        for(i = num/2; i>0; i--){
            if(isPrime(i) && isPrime(num-i))
                break;
        }
        
        cout << i << endl;
        cout << num-i << endl;
    }
    return 0;
}