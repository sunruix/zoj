#include <stdio.h>
#include <string.h>

int main()
{
	int i, j, carry, count;
	char a[32], b[32];
	while (scanf("%s %s", a + 16, b + 16) != EOF && (strcmp(a + 16, "0") || strcmp(b + 16, "0"))) {
		count = carry = 0;
		memset(a, '0', 16);
		memset(b, '0', 16);
		for (i = strlen(a) - 1, j = strlen(b) - 1; i >= 0 && j >= 0; i--, j--) {
			if (a[i] - '0' + b[j] - '0' + carry >= 10) {
				count++;
				carry = 1;
			}
			else
				carry = 0;
		}
		if (!count)
			printf("No carry operation.\n");
		else if (count == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", count);
	}
	return 0;
}

