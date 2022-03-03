#include <stdio.h>

int main ()
{
	int N, i, j, n;
	char s[128];

	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %s", &n, s);
		printf("%d ", i);
		for (j = 0; s[j] != '\0'; j++)
			if (j + 1 != n)
				printf("%c", s[j]);
		printf("\n");
	}
	return 0;
}
