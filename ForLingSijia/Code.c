#include<stdio.h>
//����������鰴������λ��ӡ
int main(int argc, char const *argv[])
{
	int *array;
	int displacement = 0, length = 0;
	int i = 0, choose=0;
	//��������ĳ��ȣ���λ�ƵĴ�С
	scanf_s("%d %d", &length, &displacement);
	switch (choose)
	{
	case 0:
		//��ͨ��������
		for (i = 0; i < length; i++)
			scanf_s("%d", &array[i]);
	case 1:
		//malloc�������鳤�ȣ�����������
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
{//1-9������1+11+111+1111.......���
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