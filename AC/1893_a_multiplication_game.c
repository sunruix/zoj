#include <stdio.h>

int main()
{
	unsigned int n, i;

	while (scanf("%ud", &n) != EOF) {
		for (i = 0; n != 1; n = i & 1 ? (n / 2 + !!(n % 2)) : (n / 9 + !!(n % 9)), i++);
		printf("%s wins.\n", i & 1 ? "Stan" : "Ollie");
	}
	return 0;
}