#include<stdio.h>
//讲输入的数组按依次移位打印
int main(int argc, char const *argv[])
{
	int *array;
	int displacement = 0, length = 0;
	int i = 0, choose=0;
	//输入数组的长度，和位移的大小
	scanf_s("%d %d", &length, &displacement);
	switch (choose)
	{
	case 0:
		//普通输入数组
		for (i = 0; i < length; i++)
			scanf_s("%d", &array[i]);
	case 1:
		//malloc定义数组长度，再输入数组
	default:
		break;
	}


	for (i = 0; i < length; i++)
	{
		if (i + displacement < length)
			printf("%d ", array[i + displacement]);
		else
			printf("%d ", array[i + displacement - length]);
	}
	printf("\n");

	printf("%d\n", another());

	return 0;
}

int another(void)
{//1-9的数如1+11+111+1111.......相加
	int a = 0, b = 0, length = 0, i = 0, sum = 0;
	//初始的数是什么，要相加几次
	printf("请输入1-9的数，相加几次，以逗号隔开\n");
	scanf_s("%d,%d", &a, &length);
	b = a;
	for (i; i < length; i++)
	{
		sum += a;
		a = a * 10 + b;
	}

	return sum;
}

int input_array(int *array,int length)
{
	array = (int*)malloc(sizeof(int)*length);
	int num = 0;
	while (num!=-1)
	{
		array = num;
		array++;
	}
}