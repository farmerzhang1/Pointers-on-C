#include <stdio.h>

int atoi(char *string) {
	int sum = 0;
	while (*string) {
		if (*string <= '9' && *string >= '0') sum = sum * 10 + *string - '0';
		else return 0;
		string++;
	}
	return sum;
}
