#include <stdio.h>
#include <string.h>

int main()
{
	int t = 1, n, m, c, o, a[32], b[32], i, cur, max, blow;

	while (scanf("%d %d %d", &n, &m, &c) != EOF && n) {
		memset(b, 0, sizeof(b)), cur = max = blow = 0;
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < m; i++) {
			scanf("%d", &o);
			b[o] ? (b[o] = 0, cur -= a[o]) : (b[o] = 1, cur += a[o]);
			cur > c ? blow = 1 : 0;
			max < cur ? max = cur : 0;
		}
		printf("Sequence %d\n", t++);
		if (blow)
			printf("Fuse was blown.\n\n");
		else {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n\n", max);
		}
	}
	return 0;
}