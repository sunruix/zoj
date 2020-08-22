#include <stdio.h>

typedef struct {
	int j, f;
} record;

int comp(const void *a, const void *b)
{
	record *r1, *r2;
	r1 = (record *)a, r2 = (record *)b;
	return (double)r1->j / r1->f > (double)r2->j / r2->f ? -1 : 1;
}

int main()
{
	int N, M, i, j;
	double res;
	record rec[1024];
	freopen("input", "r", stdin);

	while (scanf("%d %d", &M, &N) != EOF && M != -1 && N != -1) {
		for (i = 0; i < N; i++)
			scanf("%d %d", &rec[i].j, &rec[i].f);
		qsort(rec, N, sizeof(record), comp);
		for (i = 0, res = 0; i < N && M; i++) {
			if (M >= rec[i].f) {
				res += rec[i].j;
				M -= rec[i].f;
			}
			else {
				res += (double)rec[i].j / rec[i].f * M;
				M = 0;
			}
		}
		printf("%.3f\n", res);
	}
	return 0;
}
