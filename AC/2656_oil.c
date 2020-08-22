#include <stdio.h>

int main()
{
	int N, i, j, oil, res, a[10001][2];
	while (scanf("%d", &N) != EOF) {
		res = -1;
		for (i = 0; i < N; i++)
			scanf("%d %d", &a[i][0], &a[i][1]);
		for (i = 0; i < N; i++) {
			oil = 0;
			if (a[i][0] < a[i][1])
				continue;
			for (j = i; j - N < i && oil >= 0; j++)
				oil += (a[j % N][0] - a[j % N][1]);
			if (j - N == i && oil >= 0) {
				res = i;
				break;
			}
		}
		if (res >= 0)
			printf("%d\n", res);
		else
			printf("impossible\n");
	}
	return 0;
}
