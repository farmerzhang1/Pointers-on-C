#include <stdio.h>
#include <stdarg.h>
int array_offset1(int arrayinfo[], ...) {
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
	int loc = argcopy[0] - arrayinfo[1] + 
		(arrayinfo[2] - arrayinfo[1] + 1) * (argcopy[1] - arrayinfo[3]);//loc[1]
	if (arrayinfo[0] == 1) return argcopy[0] - arrayinfo[1];
	else if (arrayinfo[0] == 2) {
		return loc;
	}
	for (i = 2; i < arrayinfo[0]; i++) {
		loc = loc + (arrayinfo[2] - arrayinfo[1] + 1) *
			(argcopy[i] - arrayinfo[2 * i + 1]) * (arrayinfo[2 * i ] - arrayinfo[2 * i - 1] + 1);
	}
	return loc;
}
