#include <stdio.h>
#include <string.h>

int main()
{
	int i, n, m, count = 1;
	char s[16][32];

	while (scanf("%d", &n) != EOF && n) {
		for (i = 0; i < n; i++)
			scanf("%s", s[i]);
		printf("SET %d\n", count++);
		m = n % 2 ? n - 2 : n - 1;
		for (i = 0; i < n; i += 2)
			printf("%s\n", s[i]);
		for (i = m; i > 0; i -= 2)
			printf("%s\n", s[i]);
	}
	return 0;
}
