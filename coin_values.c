int *coin_value1[] = { 32, 228 };
int coin_value2[3] = { 3, 4, 44 };
int(*coin_value3)[3] = coin_value2;
int(*coin_value4)[3] = &coin_value2;
int *coin_value5 = (int [3]) { 234, 141};
int *coin_value6 = (int[][2]) { { 23412, 82888 }, { 23414, 5 } };
char *month[] = { "jan", "feb" };

void exp(void) {
	for (int i = 0; i < 4; i++) printf("%d\n", *coin_value6++);
}
//做实验
//orz
