/*杨辉三角变形

题目描述
            1

         1  1  1

      1  2  3  2  1

   1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。

求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。

 

输入n(n <= 1000000000)

输入描述:
	输入一个int整数
输出描述:
	输出返回的int值

示例1
	输入4
	输出3

*/


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        vector<vector<int>> dp(n, vector<int>(2*n-1, 0));
        dp[0][0] = 1;
        for(int i = 1; i < n; i++){
            dp[i][0] = dp[i][2*i] = 1;
            for(int j = 1; j < 2*i; ++j){
                if(j == 1)
                    //第二列上面的左上角到右上角只有两个元素
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-2] + dp[i-1][j-1] + dp[i-1][j];
            }
        }
        
        int k;
        for(k = 0; k < 2*n-1; ++k){
            if(dp[n-1][k] % 2 == 0){
                cout << k+1 << endl;
                break;
            }
        }
        if(k == 2*n-1)
            cout << -1 << endl;
    }
    return 0;
}