#include <stdarg.h>
#include <stdio.h>

void real_printf(const char *to_print, ...) {
	va_list var_arg;
	va_start(var_arg, to_print);
	int percent, csdf;
	while (*to_print) {
		csdf = 1;//default is true, because I am lazy, and it's more efficient (I think
		percent = 0;
		if (*to_print++ == '%') {
			percent = 1;
			if (*to_print == 'd') printf("%d", va_arg(var_arg, int));
			/*want to improve the printing of float...
			that is, include accuracy e.g.  the "%.2f"
			I am so vegetable...*/
			else if (*to_print == 'f') printf("%f", va_arg(var_arg, double));
			else if (*to_print == 'c') putchar(va_arg(var_arg, char));
			else if (*to_print == 's')
			{
				char *str = va_arg(var_arg, char*);
				//what do we do with string????  
				//well, know that string is actually a pointer
				while (*str) putchar(*str++);
			}
			else csdf = 0;			
		}//if blablabla, skip the percent mark and "csdf"
		if (percent && csdf) to_print += 2;
		putchar(*(to_print - 1));
	}
	va_end(var_arg);
}
