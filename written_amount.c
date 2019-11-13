#define _CRT_SECURE_NO_WARNINGS//sb microsoft.
#include <stdio.h>
#include <string.h>

int decimal[10] = { 0 };

int store_decimal(unsigned int amount);
void ones_digit(unsigned int amount, char *buffer);
void twos_digit(unsigned int amount, char *buffer);
void threes_digit(unsigned int amount, char *buffer);
void fours_digit(unsigned int amount, char *buffer);
void fives_digit(unsigned int amount, char *buffer);

void written_amount_sb(unsigned int amount, char *buffer) {
	//store up to 10 billion - 1 (that is really astronomical...
	//a billion: 1,000,000,000 (hundred thousand million billion)
	int num_of_digit = store_decimal(amount);
	
	switch (num_of_digit) {
	case 0: 
		strcat(buffer, "zero");
		break;
	case 1:
		ones_digit(amount, buffer);
		break;
	case 2:
		twos_digit(amount, buffer);
		break;
	case 3:
		threes_digit(amount, buffer);
		break;
	case 4:
		fours_digit(amount, buffer);
		break;
	case 5:
		fives_digit(amount, buffer);
		break;
	}
	puts(buffer);
}

int store_decimal(unsigned int amount) {
	int i = 0;
	while (amount > 0) {
		decimal[i++] = amount % 10;
		amount /= 10;
	}return i;
}

void ones_digit(unsigned int amount, char *buffer) {
	switch (amount)
	{
	case 1:
		strcat(buffer, "one");
		break;
	case 2:
		strcat(buffer, "two");
		break;
	case 3:
		strcat(buffer, "three");
		break;
	case 4:
		strcat(buffer, "four");
		break;
	case 5:
		strcat(buffer, "five");
		break;
	case 6:
		strcat(buffer, "six");
		break;
	case 7:
		strcat(buffer, "seven");
		break;
	case 8:
		strcat(buffer, "eight");
		break;
	case 9:
		strcat(buffer, "nine");
		break;
	default:
		;
	}
}

void twos_digit(unsigned int amount, char *buffer) {
	switch (amount) {
	case 10:
		strcat(buffer, "ten");
		break;
	case 11:
		strcat(buffer, "eleven");
		break;
	case 12:
		strcat(buffer, "twelve");
		break;
	case 13:
		strcat(buffer, "thirteen");
		break;
	case 14:
		strcat(buffer, "fourteen");
		break;
	case 15:
		strcat(buffer, "fifteen");
		break;
	case 16:
		strcat(buffer, "sixteen");
		break;
	case 17:
		strcat(buffer, "seventeen");
		break;
	case 18:
		strcat(buffer, "eighteen");
		break;
	case 19:
		strcat(buffer, "ninteen");
		break;
	default:
		ones_digit(decimal[1], buffer);
		strcat(buffer, "ty ");
		ones_digit(decimal[0], buffer);
	}
}

void threes_digit(unsigned int amount, char *buffer) {
	ones_digit(decimal[2], buffer);
	strcat(buffer, " hundred ");
	if (decimal[1] != 0) {
		strcat(buffer, "and ");
		twos_digit(decimal[1] * 10 + decimal[0], buffer);
	}
	else if (decimal[0] != 0) {
		strcat(buffer, "and ");
		ones_digit(decimal[0], buffer);
	}
	
}

void fours_digit(unsigned int amount, char *buffer) {
	ones_digit(decimal[3], buffer);
	strcat(buffer, " thousand ");
	if (decimal[2] != 0) threes_digit(amount - decimal[3] * 1000, buffer);
	else if (decimal[1] != 0) twos_digit(decimal[0] + decimal[1] * 10, buffer);
	else ones_digit(decimal[0], buffer);
}

void fives_digit(unsigned int amount, char *buffer) {
	;//there must be another way, I looked a less complicated code of an experienced programmer, only take 70+ lines...
}
