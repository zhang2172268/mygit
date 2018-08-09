#include <stdio.h>
#include <math.h>

//素数是不能被2到本身开方之间任一整数整除的整数
int main()
{
	int i, j, k;
	printf("100--200间的素数输出:\n");
	for (i = 100; i <= 200; i++)
	{
		k = sqrt(i);
		for (j = 2; j <= k; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j > k )
			printf("%d\ ", i);
	}
	printf(" \n ");
	system("pause");
	return 0;
}

