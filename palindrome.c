#include <stdio.h>

int palindrome(char *source) {
	char *back = source;
	while (*back++);
	back -= 2;
	while (back - source >= 0) if (*back-- != *source++) {
		printf("no!!!\n");
		return 0;
	}
	printf("yes!!!\n");
	return 1;
}
