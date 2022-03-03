#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double d;
	int i;
} record;

int comp1(const void *a, const void *b)
{
	record *r1, *r2;
	r1 = (record *)a, r2 = (record *)b;
	if (r1->d < r2->d)
		return 1;
	else if (r1->d > r2->d)
		return -1;
	else
		return r1->i - r2->i;
}

int comp2(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int N, M, K, i, j, k, index[10000];
	double a;
	record rec[10000];
	freopen("input1", "r", stdin);
	while (scanf("%d %d %d", &N, &M, &K) != EOF) {
		for (i = 0; i < M; i++) {
			rec[i].d = 0;
			rec[i].i = i;
		}
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++) {
				scanf("%lf", &a);
				rec[j].d += a;
			}
		qsort(rec, M, sizeof(record), comp1);
		for (i = 0; i < K; i++)
			index[i] = rec[i].i;
		qsort(index, K, sizeof(int), comp2);
		for (i = 0; i < K - 1; i++)
			printf("%d ", index[i] + 1);
		printf("%d\n", index[i] + 1);
	}
	return 0;
}


#include <stdio.h>

int comp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int main()
{
	int N, M, K, i, j, k, index[32768];
	double v[32768], a, m, max;

	while (scanf("%d %d %d", &N, &M, &K) != EOF) {
		for (i = 0; i < M; i++)
			v[i] = 0;
		for (i = 0, max = 0; i < N; i++)
			for (j = 0; j < M; j++) {
				scanf("%lf", &a);
				v[j] += a;
				if (v[j] > max) {
					max = v[j];
					index[0] = j;
				}
			}
		v[index[0]] = -1.7e+308;
		for (i = 1; i < K; i++) {
			for (j = 0, m = 0; j < M; j++)
				if (v[j] <= max && v[j] > m) {
					m = v[j];
					index[i] = j;
				}
			max = m;
			v[index[i]] = -1.7e+308;
		}
		qsort(index, K, sizeof(int), comp);
		for (i = 0; i < K - 1; i++)
			printf("%d ", index[i] + 1);
		printf("%d\n", index[i] + 1);
	}
	return 0;
}

