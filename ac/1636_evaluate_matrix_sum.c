#include <stdio.h>
#include <string.h>

int  main()
{
	int T, t, r1, c1, r2, c2, r, c, a[501][501], i, j, k, n, ans;

	memset(a, 0, sizeof(a));
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d %d", &r, &c);
		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++) {
				scanf("%d", &k);
				a[i][j] = k * k + a[i][j - 1];
			}
		scanf("%d", &n);
		printf("Case %d:\n", t);
		while (n--) {
			scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
			for (ans = 0, i = r1; i <= r2; i++)
				ans += a[i][c2] - a[i][c1 - 1];
			printf("%d\n", ans);
		}
	}
	return 0;
}