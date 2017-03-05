#include<stdio.h>
int main(void)
{
	int array[100];
	int displacement = 0, length = 0;
	int i = 0;

	scanf_s("%d %d", &length, &displacement);

	for (i = 0; i < length; i++)
		scanf_s("%d", &array[i]);

	for (i = 0; i < length; i++)
	{
		if (i + 3 < length)
			printf("%d ", array[i + displacement]);
		else
			printf("%d ", array[i + displacement - length]);
	}

	return 0;
}