#include <stdio.h>
#include <string.h>

int main()
{
	int t, n, a, b, c, i, max, m[256];

	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(m, 0, sizeof(m));
		while (n--) {
			scanf("%d %d", &a, &b);
			c = a > b ? a : b;
			a = a < b ? a : b;
			b = c;
			a = (a - 1) / 2, b = (b - 1) / 2;
			for (i = a; i <= b; i++)
				m[i]++;
		}
		for (i = max = 0; i < 200; i++)
			if (max < m[i])
				max = m[i];
		printf("%d\n", 10 * max);
	}
	return 0;
}