#include <stdio.h>
#include <string.h>

int main()
{
	int N, Q, M, date[64][128], i, j, k, yes;

	while (scanf("%d %d", &N, &Q) != EOF && N) {
		memset(date, 0, sizeof(date));
		for (i = 0; i < N; i++) {
			scanf("%d", &M);
			while (M--) {
				scanf("%d", &j);
				date[i][j] = 1;
			}
		}
		for (k = N, yes = k; k >= Q && yes > 0; k--) {
			for (j = 0; j < 128 && yes > 0; j++) {
				for (i = 0, yes = k; i < N && yes > 0; i++)
					yes -= date[i][j];
				if (yes <= 0)
					break;
			}
		}
		if (yes > 0)
			printf("0\n");
		else
			printf("%d\n", j);
	}
	return 0;
}
