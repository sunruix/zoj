#include <stdio.h>

int N, x, a[16], total;
int gcd (int n, int m)
{
	int p;
	while ((p = n % m)) {
		n = m;
		m = p;
	}
	return m;
}

int lgm(int n, int m)
{
	if (n > m)
		return n * m / gcd(n, m);
	return m * n / gcd(m, n);
}

void dfs (int s, int l, int ll, int arg)
{
	int i;
	if (!l)
		total += x / a[s];
	else if (!ll)
		total += x / lgm(a[s], arg);
	else {
		for (i = s + 1; i + ll <= N; i++)
			dfs(i, l, ll - 1, lgm(a[s], arg));
	}
}

int main()
{
	int sum, i, j, k;

	while (scanf("%d %d", &N, &x) != EOF) {
		sum = 0;
		for (i = 0; i < N; i++)
			scanf("%d", &a[i]);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				total = 0;
				dfs(j, i, i, 1);
				if (!(i % 2))
					sum += total;
				else
					sum -= total;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}

