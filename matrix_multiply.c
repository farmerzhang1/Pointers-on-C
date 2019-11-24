#include <stdio.h>
/*
m1[x][y]
m2[y][z]
r[x][z]
*/
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z) {
	int i, j, k;
	for (i = 0; i < x; i++) {
		for (j = 0; j < z; j++) {
			*(r + z * i + j) = 0;
			for (k = 0; k < y; k++) {
				*(r + z * i + j) += *(m1 + i * y + k) * *(m2 + k * z + j);
			}
		}
	}
}
