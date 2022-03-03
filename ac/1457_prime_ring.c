#include <stdio.h>

int n, visited[32], path[32];

int isprime(int n)
{
	return n == 3 || n == 5 || n == 7 || n == 11 ||
		n == 13 || n == 17 || n == 19 || n == 23 ||
		n == 29 || n == 31 || n == 37;
}

void dfs(int x, int pos)
{
	int i;

	visited[x] = 1, path[pos] = x;
	if (pos == n) {
		if (isprime(x + 1)) {
			for (i = 1; i < n; i++)
					printf("%d ", path[i]);
				printf("%d\n", path[i]);
		}
		visited[x] = 0; return;
	}
	for (i = x % 2 ? 2 : 3; i <= n; i += 2)
		if (!visited[i] && isprime(x + i))
			dfs(i, pos + 1);
	visited[x] = 0; return;
}

int main()
{
	int i, count = 1;
	
	path[1] = 1;
	while (scanf("%d", &n) != EOF) {
		printf("Case %d:\n", count++);
		if (!(n % 2))
			for (i = 2; i <= n; i += 2)
				if (isprime(1 + i))
					dfs(i, 2);
		printf("\n");
	}
	return 0;
}
	