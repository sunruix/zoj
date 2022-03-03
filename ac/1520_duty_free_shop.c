#include <stdio.h>
#include <string.h>

int main()
{
	int M, L, n, a[2048], i, j, m[1024], path[1024], ans[1024], sum;

	while (scanf("%d %d", &M, &L) != EOF && (M || L)) {
		scanf("%d", &n);
		for (sum = 0, i = 1; i <= n; i++)
			scanf("%d", &a[i]), sum += a[i];
		if (sum > M + L) {
			printf("Impossible to distribute\n");
			continue;
		}
		memset(m, 0, sizeof(m)), memset(path, 0, sizeof(path)), m[0] = 1;
		for (i = 1; i <= n; i++) {
			for (j = M; j >= a[i]; j--) {
				m[j] = m[j] || m[j - a[i]];
				m[j - a[i]] && !path[j] ? (path[j] = i) : 0;
			}
		}
		for (j = M; j >= 0 && !m[j]; j--);
		if (sum - j > L)
			printf("Impossible to distribute\n");
		else {
			for (i = 0; j; i++)
				ans[i] = path[j], j -= a[path[j]];
			for (printf("%d%c", i, i ? ' ' : '\n'), i--; i >= 0; i--)
				printf("%d%c", ans[i], i ? ' ' : '\n');
		}
	}
	return 0;
}