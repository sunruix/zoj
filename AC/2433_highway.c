#include <stdio.h>

int main()
{
	int T, N, dist[50005], i, min, index;

	while (scanf("%d", &T) != EOF) {
		while (T--) {
			scanf("%d", &N);
			for (i = 1; i <= N - 1; i++)
				scanf("%d", &dist[i + 1]);
			if (N <= 3)
				printf("0\n");
			else {
				for (i = 3, min = 0x7fffffff; i <= N - 1; i++)
					if (dist[i] - dist[i - 1] < min) {
						min = dist[i] - dist[i - 1];
						index = i;
					}
				printf("%d\n", dist[index] + dist[N] - dist[index - 1]);
				printf("%d 1 %d %d\n", index, N, index - 1);
			}
			if (T)
				printf("\n");
		}
	}
	return 0;
}

			
