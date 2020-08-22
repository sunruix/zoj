#include <stdio.h>
#include <string.h>

int main()
{
	int z, i, l, m, k, x, count, map[10000];

	count = 1;
	while (scanf("%d %d %d %d", &z, &i, &m, &l) != EOF && (z || i || m || l)) {
		memset(map, 0, sizeof(map));
		for (k = map[l] = 1; ; k++) {
			l = (z * l + i) % m;
			if (map[l])
				break;
			map[l] = k + 1;
		}
		printf("Case %d: %d\n", count++, k - map[l] + 1);
	}
	return 0;
}