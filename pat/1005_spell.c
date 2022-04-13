#include <stdio.h>
#include <string.h>

int main()
{
	char digit[128];
	char map[10][10] = {"zero", "one", "two", "three", "four", "five", 
		"six", "seven", "eight", "nine"};
	char result[5][10];
	int i, j, sum = 0;

	scanf("%s", digit);
	for (i = 0; digit[i] != '\0'; i++)
		sum += digit[i] - '0';
	if (!sum) {
		printf("%s\n", map[sum]);
		return 0;
	}
	for (i = 0;  sum != 0; i++) {
		strcpy(result[i], map[sum % 10]);
		sum /= 10;
	}
	for (--i; i > 0; i--) {
		printf("%s ", result[i]);
	}
	printf("%s\n", result[i]);
	return 0;
}
