#include<stdio.h>
#include<malloc.h>
#include<time.h>
int another(void);

//����������鰴������λ��ӡ
int main(int argc, char const *argv[])
{
	//��������ʱ��Ķ���
	clock_t start, finish;
	double duration;
	
	int *array;
	int displacement = 0, length = 0, num = 0;
	int i = 0, choose=0;

	printf("��������ĳ��ȣ���λ�ƵĴ�С���Կո����\n");
	scanf_s("%d %d", &length, &displacement);
	//�������鳤��
	array = (int*)malloc(sizeof(int)*length);

	for (i; i<length; i++)
	{
		printf("��ʼ���������%d��:", i + 1);
		scanf_s("%d", &num);
		*(array + i) = num;
	}

	start = clock();//��ʱ��ʼ

	for (i = 0; i < length; i++)
	{
		if (i + displacement < length)
			printf("%d ", array[i + displacement]);
		else
			printf("%d ", array[i + displacement - length]);
	}

	{	
		//��ӡ���е�ʱ��
		finish = clock();//��ʱ����
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("Time: %fms\n", duration * 1000);
	}

	printf("\n���������another��������1��������������һ��1����\n");
	scanf_s("%d", &choose);
	start = clock();//��ʱ��ʼ
	if(choose==1)
		printf("%d\n", another());
	{
		//��ӡ���е�ʱ��
		finish = clock();//��ʱ����
		duration = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("Time: %fms\n", duration * 1000);
	}
	return 0;
}

int another(void)
{
	//1-9������1+11+111+1111.......���
	int a = 0, b = 0, length = 0, i = 0, sum = 0;
	//��ʼ������ʲô��Ҫ��Ӽ���
	printf("������1-9��������Ӽ��Σ��Զ��Ÿ���\n");
	scanf_s("%d,%d", &a, &length);
	b = a;
	for (i; i < length; i++)
	{
		sum += a;
		a = a * 10 + b;
	}

	return sum;
}