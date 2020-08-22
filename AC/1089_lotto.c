#include <stdio.h>

int n, ary[50], path[6];

void dfs(int pos, int len)
{
	int i;
	if (!len) {
		for (i = 0; i < 5; i++)
			printf("%d ", path[i]);
		printf("%d\n", ary[pos]);
		return;
	}
	else {
		path[5 - len] = ary[pos];
		for (i = pos + 1; i < n - len + 1; i++)
			dfs(i, len - 1);
	}
}

int main()
{
	int i, j, k = 0;
	while (scanf("%d", &n) != EOF && n) {
		if (k++) 
			printf("\n");
		for (i = 0; i < n; i++)
			scanf("%d", &ary[i]);
		for (i = 0; i <= n - 6; i++)
			dfs(i, 5);
	}
	return 0;
}
