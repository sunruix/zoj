#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, a[16];
	char s[16];

	while (scanf("%d\n", &n) != EOF && n) {
		gets(s);
		if (!strcmp(s, "too high"))
			for (i = n; i <= 10; i++)
				a[i] = 0;
		else if (!strcmp(s, "too low"))
			for (i = 1; i <= n; i++)
				a[i] = 0;
		else {
			if (a[n])
				printf("Stan may be honest\n");
			else
				printf("Stan is dishonest\n");
			memset(a, 1, sizeof(a));
		}
	}
	return 0;
}
