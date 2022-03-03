#include <stdio.h>
#include <string.h>

int main()
{
	int N, W, H, S, T, i, j, count, max;
	int map[128][128], w, h;
	while (scanf("%d", &N) != EOF && N) {
		scanf("%d %d", &W, &H);
		memset(map, 0, sizeof(map));
		while (N--) {
			scanf("%d %d", &i, &j);
			map[i][j] = 1;
		}
		scanf("%d %d", &S, &T);
		max = 0;
		for (w = 1; w + S - 1<= W; w++)
			for (h = 1; h + T - 1 <= H; h++) {
				count = 0;
				for (i = w; i < w + S; i++)
					for (j = h; j < h + T; j++)
						count += map[i][j];
				if (count > max)
					max = count;
			}
		printf("%d\n", max);
	}
	return 0;
}
