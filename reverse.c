/*#include <stdio.h>

void reverse(char str[]);
int strlen(char const *str);

int main(void)
{
	char str[] = "if you dare then reverse me.";
	reverse(str);
	puts(str);
	system("pause");
}
void reverse(char str[])
{
	int len = strlen(str);
	int tmp;
	for (int i = 0; 2 * i < len - 1; i++)
	{
		if (str[i] != str[len - i - 1]) {//exchange
			str[i] ^= str[len - i - 1];
			str[len - i - 1] ^= str[i];
			str[i] ^= str[len - i - 1];
		}
	} 
}

int strlen(char const *str)
{
	int i = 0;
	while (*str++) i++;	
	return i;
}*/


#include<stdio.h>

#define NUL '\0'

void reverse_string(char *string);

int main(int argc, char const *argv[]) {
	char str[] = "abcdefghi";
	reverse_string(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}

void reverse_string(char *string)
{
	char *last_string = string;
	char *pre_string = string;
	char temp_ch = 0;

	while (*last_string++ != NUL);
	last_string -= 2;
	//*last_string = 'H';

	while (pre_string < last_string) {
		temp_ch = *pre_string;
		*pre_string++ = *last_string;
		*last_string-- = temp_ch;
	}
}
