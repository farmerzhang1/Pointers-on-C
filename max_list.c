#include <stdarg.h>

int max(int n, ...) {
	va_list var_arg;
	int max = n;
	
	va_start(var_arg, n);
	int tmp;
	while ((tmp = va_arg(var_arg, int)) >= 0)	
		if (max < tmp)
			max = tmp;
	
	
	va_end(var_arg);

	return max;
}
