#include <stdio.h>

int del_str(char *str, char const *substr);
int strlen(char const *str);
int isSame(char *str, char const *substr);

int main(void)
{
	char *str = "hhhajhhh";
	char const *substr = "aj";
	del_str(str, substr);
	
	while (*str) putchar(*str++);
	putchar('\n');
	system("pause");
}

int del_str(char *str, char const *substr)
{
	//first we find if there is a sub-string 
	int find = 0;
	int sublen = strlen(substr);
	while (*str)
	{
		if (isSame(str++, substr)) {
			find = 1;
			break;
		}
	}
	//now if we find the str
	if (find)
	{
		str--;
		//the next four lines... too hard for me, don't understand
		char *pstr = '\0';
		char const *psubstr = '\0';
		pstr = str;
		psubstr = substr;
		while (substr != '\0')
		{
			substr++;
			str++;
		}
		while (*pstr++ = *str++);

	}
}

int strlen(char const *str)
{
	int i = 0;
	while (*str++)
	{
		i++;
	}
	return i;
}

int isSame(char *str, char const *substr)
{
	int i = 0;
	int found = 0;
	while (*substr != '\0') {
		i++;
		if (*substr++ == *str++)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	if (*substr == '\0' && *--substr == *--str) found = 1;
	str -= i-1;
	substr -= i-1;//go back to where it starts
	return found;
}

