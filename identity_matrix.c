#include <stdio.h>

int identity_matrix(int *num1, int size) {
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((j != i && *num1 == 0) || (j == i && *num1 == 1));
			else
				return 0;
			num1++;
		}
	}
	return 1;
}
