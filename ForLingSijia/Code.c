#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<string.h>
#include<errno.h>

int** askForArray2D(int rows, int columns);//定义二维数组
void freeMalloc2D(int** array, int rows);//记得要free，malloc
long long another(void);
void errorExperiment();

//将输入的数组按依次移位打印
int main(int argc, char const *argv[])
{
	//计算运行时间的定义
	clock_t start, finish;
	double duration;
	
	int *array;
	int displacement = 0;//位移
	int length = 0;//一维数组长度
	int num = 0;
	int choose = 0;
	int i = 0;

	printf("输入数组的长度，和位移的大小，以\",\"隔开\n");
	scanf_s("%d,%d", &length, &displacement);
	//定义一维数组长度
	array = (int*)malloc(sizeof(int*)*length);

	//定义二维数组
	{
		int rows = 0;
		int columns = 0;
		int** array;

		printf("请输入行与列以\"，\"隔开\n");
		scanf_s("%d,%d", &rows, &columns);

		array=askForArray2D(rows, columns);
		
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				array[i][j] = i*columns + j;
				printf("array[%d][%d]=%d\t", i, j, array[i][j]);
			}
			printf("\n");
		}
		
		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				array[i][j] = i*columns + j;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				printf("array[%d][%d]=%2d\t", i, j, array[i][j]);
			printf("\n");
		}
			



		freeMalloc2D(array, rows);
	}

	for (i; i < length; i++)
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
	if (choose == 1)
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
int** askForArray2D(int rows, int columns)//P.S.里面有乘号...
{
	int **array;
	char* strerroe(int errnum);
	array = (int**)malloc(sizeof(int*)*rows);//先获取行指针
	if (NULL == array)
		perror("error:");
	exit(1);
	for (int i = 0; i < rows; i++)
	{
		array[i] = (int*)malloc(sizeof(int)*columns);//再定义列指针
		if (NULL == array)
			perror("error:");
	}


	return array;
}
void freeMalloc2D(int** array, int rows)
{
	for (int i = 0; i < rows; i++)
		free(array[i]);

	free(array);
}

void errorExperiment()
{
	FILE * fp;
	int errnum;
	fp = fopen_s(&fp,"unexist.txt", "rb");
	if (fp == NULL)
	{
		errnum = errno;
//		fprintf(stderr, "Value of errno: %d -by www.yiibai.com \n", errno);
		perror("Error printed by perror");
//		fprintf(stderr, "Error opening file: %s\n", strerror_s(errnum));
	}
	else
	{
		fclose(fp);
	}

	int dividend = 20;
	int divisor = 0;
	int quotient;

	if (divisor == 0) {
		fprintf(stderr, "Division by zero! Exiting...\n");
		exit(-1);
	}
	quotient = dividend / divisor;
	fprintf(stderr, "Value of quotient : %d\n", quotient);

	exit(0);
}