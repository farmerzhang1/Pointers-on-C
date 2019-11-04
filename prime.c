#include <stdio.h>

void cross_bang(int numbers[]);

int main(void)
{
	int numbers[10000];
	
	int i;
	for (i = 0; i < 1000; i++) numbers[i] = 1;
	numbers[++i] = 2;//end of the string.
	cross_bang(numbers);
	for (i = 1; i < 1000; i++)	
		if (numbers[i]) 
			printf("%d\n", i + 1);
	
	system("pause");
}

void cross_bang(int numbers[])
{	
	int *num = numbers;//mark the start of the numbers, which is the place of numbers[0]
	numbers++;
	while (*numbers != 2)
	{
		int *num1 = numbers++;
		if (*num1)
		{
			int the_prime = num1 - num + 1;
			while (num1 - num <= 1000)
			{				
				num1 += the_prime;
				*num1 = 0;
			}
		}
	}
}
