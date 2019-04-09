/*
[编程题]斐波那契凤尾

NowCoder号称自己已经记住了1 - 100000之间所有的斐波那契数。为了考验他，我们随便出一个数n，
让他说出第n个斐波那契数。当然，斐波那契数会很大。因此，如果第n个斐波那契数不到6位，则说出该数；否则只说出最后6位。

输入描述 :
输入有多组数据。
每组数据一行，包含一个整数n(1≤n≤100000)。

输出描述 :
对应每一组输入，输出第n个斐波那契数的最后6位。

示例1
输入
1
2
3
4
100000

输出
1
2
3
5
537501
*/

#include <iostream>
#include <cstdio>

int main()
{
	int fib[100001];
	fib[0] = 1;
	fib[1] = 1;

	for (int i = 2; i <= 100000; ++i){
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] = fib[i] % 1000000;
	}

	int n;
	while (std::cin >> n){
		if (n < 29)
			printf("%d\n", fib[n]);
		else
			printf("%06d\n", fib[n]);
	}
	return 0;
}