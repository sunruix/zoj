#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char s[64];
	int invers;
} node;

int comp(const void *a, const void *b)
{
	return ((node *)a)->invers - ((node *)b)->invers;
}

int main()
{
	int N, n, l, i, j, k;
	node a[128];

	while (scanf("%d", &N) != EOF) {
		while (N--) {
			scanf("%d %d", &l, &n);
			for (i = 0; i < n; i++) {
				scanf("%s", a[i].s);
				a[i].invers = 0;
				for (j = l - 1; j >= 0; j--)
					for (k = j - 1; k >= 0; k--)
						if (a[i].s[j] < a[i].s[k])
							a[i].invers++;
			}
			qsort(a, n, sizeof(node), comp);
			for (i = 0; i < n; i++)
				printf("%s\n", a[i].s);
			if (N)
				printf("\n");
		}
	}
	return 0;
}
