#include <stdio.h>

int main()
{
	int i, t, sum, n, N;
	scanf("%d", &N);
	for (t = 1; t <= N; t++) {
		sum = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
			sum += i * (i + 1) * (i + 2);
		printf("%d %d %d\n", t, n, sum / 2);
	}
	return 0;
}
