#include <stdio.h>
#include <stdarg.h>

int array_offset0(int arrayinfo[], ...) {
	int argcopy[20];
	int i;
	if (arrayinfo[0] > 10 || arrayinfo[0] < 0) {//check arrayinfo[0]
		printf("fuck you!!!!\nenter a correct number\n");
		return -1;
	}
	va_list arg;
	va_start(arg, arrayinfo);
	for (i = 0; i < arrayinfo[0]; i++) {
		argcopy[i] = va_arg(arg, int);
	}
	va_end(arg);
	//let's check some input errors
	for (i = 0; i < arrayinfo[0]; i++) {
		if (!(arrayinfo[2 * i + 1] <= argcopy[i]) || !(arrayinfo[2 * i + 2] >= argcopy[i])) {
			printf("fuck you!!!!\nenter a correct number\n");
			return -1;
		}
	}
	//formula: loc[i] = loc[i - 1] * (hi[i] - lo[i] + 1) + s[i] - lo[i];
	//loc[0] = s[0] - lo[0];
	int loc = argcopy[0] - arrayinfo[1];
	for (i = 1; i < arrayinfo[0]; i++)
		loc = loc * (arrayinfo[2 * i + 2] - arrayinfo[2 * i + 1] + 1) 
		+ argcopy[i] - arrayinfo[2 * i + 1];
	return loc;
}
