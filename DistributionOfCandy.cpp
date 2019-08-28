/*********************************************
 派分糖果


  题目描述
	有N个孩子站成一排，每个孩子有一个分值。给这些孩子派发糖果，需要满足如下需求：

	1、每个孩子至少分到一个糖果

	2、分值更高的孩子比他相邻位的孩子获得更多的糖果

	求至少需要分发多少糖果？

	输入
		5,4,1,1
	输出
		7

**********************************************/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, x, s = 0;
    vector<int> a;
    while(cin>>x){
        a.push_back(x);
        if(cin.get()=='\n')
            break;
    }
    n = a.size();
    vector<int> b(n,1);
    for(int i=1;i<n;i++)
        if(a[i]>a[i-1])
            b[i] = b[i-1] + 1;
    for(int i=n-1;i>0;i--)
        if(a[i]<a[i-1] && b[i]>=b[i-1])
            b[i-1] = b[i] + 1;
    s = 0;
    for(int i=0;i<n;i++)
        s += b[i];
    cout<<s<<endl;     
    return 0;
}

