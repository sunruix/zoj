#include <stdio.h>

int main()
{
	int N, m, n, a, b, count, i;

	scanf("%d", &N);
	while (N--) {
		i = 1;
		while (scanf("%d %d", &n, &m) != EOF && (n || m)) {
			count = 0;
			for (b = 2; b < n; b++)
				for (a = 1; a < b; a++)
					if (!((a * a + b * b + m) % (a * b)))
						count++;
			printf("Case %d: %d\n", i++, count);
		}
		if (N)
			printf("\n");
	}
	return 0;
}
