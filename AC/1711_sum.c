#include <stdio.h>

int sum, n, a[128], p[128];
int dfs(int left, int s, int d)
{
	int i, flag = 0, pre = -1;
	if (!left) {
		for (i = 0; i < d - 1; i++)
			printf("%d+", p[i]);
		printf("%d\n", p[i]);
		return 1;
	}
	for (i = s; i < n; i++) {
		if (a[i] == pre)
			continue;
		pre = a[i];
		if (left >= a[i]) {
			p[d] = a[i];
			if (dfs(left - a[i], i + 1, d + 1))
				flag = 1;
		}
	}
	return flag;

}

int main()
{
	int i;

	while (scanf("%d %d", &sum, &n) != EOF && (sum || n)) {
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		printf("Sums of %d:\n", sum);
		if (!dfs(sum, 0, 0))
			printf("NONE\n");
	}
	return 0;
}
