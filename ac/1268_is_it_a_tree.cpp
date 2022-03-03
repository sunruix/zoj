#include <stdio.h>
#include <string.h>

int main()
{
	int i, v, w, ans, d[327688][2], max, min, count = 1;

	memset(d, 0, sizeof(d)), max = 0, min = 0x7fffffff, ans = 0;
	while (scanf("%d %d", &v, &w) != EOF && v >= 0 && w >= 0) {
		if (!v || !w) {
			if (ans == 0) {
				for (i = min; i <= max; i++) {
					if (d[i][0] > 1) {
						ans = 0;
						break;
					}
					else if (d[i][1] && !d[i][0])
						ans++;
				}
			}
			if (ans == 1 || max == 0)
				printf("Case %d is a tree.\n", count++);
			else
				printf("Case %d is not a tree.\n", count++);
			memset(d, 0, sizeof(d)), max = 0, min = 0x7fffffff, ans = 0;
			continue;
		}
		d[v][1]++, d[w][0]++;
		if (v == w) ans = -1;
		if (max < v) max = v; if (max < w) max = w;
		if (min > v) min = v; if (min > w) min = w;
	}
	return 0;
}
		