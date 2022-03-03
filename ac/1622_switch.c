#include <stdio.h>

int main()
{
	int n, i, a, b, s[32768];
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++)
			scanf("%d", &s[i]);
		for (i = 0, a = 0; i < n; i++)
			if (((i % 2) && s[i] != 1) || !(i % 2) && s[i] != 0)
				a++;
		for (i = 0, b = 0; i < n; i++)
			if (((i % 2) && s[i] != 0) || !(i % 2) && s[i] != 1)
				b++;
		printf("%d\n", a < b ? a : b);
	}
	return 0;
}
