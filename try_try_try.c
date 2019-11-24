#include <stdio.h>
#define SIZE  500000 
int  x[SIZE]; 
int  y[SIZE]; 
int  i; 
int *p1, *p2;

void try1() {
	for (i = 0; i < SIZE; i++) 
		x[i] = y[i];
}

void try5() {
	register int *p1, *p2;
	for (p1 = x, p2 = y; p1 <= x + SIZE;)
		*p1++ = *p2++;
}

int main(void) {
	try1();
	return 0;
}
