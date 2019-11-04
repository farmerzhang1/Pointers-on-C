#include<stdio.h>
int find_char(char *source, char const *chars);

int main(void)
{

	char *source = "la;jdf;aj;jiiiiiiiiiiiiqooq";
	char const *chars = "lllz";
	find_char(source, chars);
	system("pause");
}
int find_char(char *source, char const *chars)
{
	int i = 0;
	int find = 0;
	char **val = &source;
	while (*chars)
	{
		for (; **val != '\0'; (*val)++)
		{
			if (*chars == **val)
			{
				find = 1; break;
			}
			i++;
		}
		if (find) break;//this is good.		
		chars++;
		*val -= i;//remember to go back you fucking idiot!!!
		i = 0;
	}
	if (*chars)printf("%c\n", *chars);
	else printf("fuck you\n");
}
