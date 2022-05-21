#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

int main()
{
	int i, temp, carry;
	char s[32], t[32], ans[32];

	scanf("%s", s + 1);
	strcpy(t + 1, s + 1);
	s[0] = t[0] = '0';
	for (i = strlen(t) - 1, carry = 0; i >= 0; i--) {
		temp = 2 * (t[i] - '0') + carry;
		carry = 0;
		if (temp >= 10) {
			temp -= 10;
			carry = 1;
		}
		t[i] = temp + '0';
	}
	strcpy(ans, t);
	qsort(s, strlen(s), sizeof(char), comp);
	qsort(t, strlen(t), sizeof(char), comp);
	if (ans[0] != '0' || strcmp(s, t))
		printf("No\n");
	else
		printf("Yes\n");
	if (ans[0] == '0')
		printf("%s\n", ans + 1);
	else
		printf("%s\n", ans);
	return 0;
}
