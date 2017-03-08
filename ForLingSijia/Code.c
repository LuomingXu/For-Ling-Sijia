#include<stdio.h>
#include<malloc.h>
#include<time.h>

long long another(void);

//将输入的数组按依次移位打印
int main(int argc, char const *argv[])
{
	//计算运行时间的定义
	clock_t start, finish;
	double duration;
	
	int *array;
	int displacement = 0;
    int length = 0;
    int num = 0;
    int choose = 0;
	int i = 0;

	printf("输入数组的长度，和位移的大小，以\",\"隔开\n");
	scanf_s("%d,%d", &length, &displacement);
	//定义数组长度
	array = (int*)malloc(sizeof(int)*length);

	for (i; i<length; i++)
	{
		printf("开始输入数组第%d个:", i + 1);
		scanf_s("%d", &num);
		*(array + i) = num;
	}

	start = clock();//计时开始

	for (i = 0; i < length; i++)
	{
		if (i + displacement < length)
			printf("%d ", array[i + displacement]);
		else
			printf("%d ", array[i + displacement - length]);
	}

	{	
		//打印运行的时间
		finish = clock();//计时结束
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("Time: %fms\n", duration * 1000);
	}

	printf("\n如果你想做another，请输入1，不想请输入任一非1的数\n");
	scanf_s("%d", &choose);
	start = clock();//计时开始
	if(choose==1)
		printf("%lld\n", another());
	{
		//打印运行的时间
		finish = clock();//计时结束
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("Time: %fms\n", duration * 1000);
	}
	return 0;
}

long long another(void)
{
	//1-9的数如1+11+111+1111.......相加
	int a = 0, b = 0, length = 0, i = 0;
	long long sum = 0;
	//初始的数是什么，要相加几次
	printf("请输入1-9的数，相加几次，以\",\"隔开\n");
	scanf_s("%d,%d", &a, &length);
	b = a;
	for (i; i < length; i++)
	{
		sum += a;
		a = a * 10 + b;
	}

	return sum;
}
