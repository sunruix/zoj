#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char s[8];
	int n;
} record;

int comp(const void *a, const void *b)
{
	return strcmp(((record *)a)->s, ((record *)b)->s);
}

int main()
{
	int i, n, d, a[8];
	char c[8];
	record m[83681], *ans;

	for (memset(m, 0, sizeof(m)), n = d = 0; d < 5; d++) {
		for (a[0] = 0, c[0] = 'a'; a[0] <= d && c[0] <= 'z'; c[0]++) {
			a[0] == d ? (m[n].n = n), strncpy(m[n++].s, c, d + 1) : 0;
			for (a[1] = 1, c[1] = c[0] + 1; a[1] <= d && c[1] <= 'z'; c[1]++) {
				a[1] == d ? (m[n].n = n), strncpy(m[n++].s, c, d + 1) : 0;
				for (a[2] = 2, c[2] = c[1] + 1; a[2] <= d && c[2] <= 'z'; c[2]++) {
					a[2] == d ? (m[n].n = n), strncpy(m[n++].s, c, d + 1) : 0;
					for (a[3] = 3, c[3] = c[2] + 1; a[3] <= d && c[3] <= 'z'; c[3]++) {
						a[3] == d ? (m[n].n = n), strncpy(m[n++].s, c, d + 1) : 0;
						for (a[4] = 4, c[4] = c[3] + 1; a[4] <= d && c[4] <= 'z'; c[4]++) {
							a[4] == d ? (m[n].n = n), strncpy(m[n++].s, c, d + 1) : 0;
						}
					}
				}
			}
		}
	}
	qsort(m, n, sizeof(record), comp);
	while (scanf("%s", c) != EOF) {
		if (ans = bsearch(c, m, n, sizeof(record), comp))
			printf("%d\n", ans->n + 1);
		else
			printf("0\n");
	}
	return 0;
}
		