#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int c, m, t0, t1;
	int v, w, x;
	int status;
	int early;
} job;
job jobs[100001];

int comp(const void *j0, const void *j1)
{
	int result = 0;
	job *p0, *p1;
	p0 = (job *)j0, p1 = (job *)j1;
	if (p0->t0 == p1->t0)
		return p0->v < p1->v ? 1 : -1;
	else
		return p0->t0 > p1->t0 ? 1 : -1;
}

int main() 
{
	int F, M, N, L, i, j, t, count = 0;
	int curc, curm, rec, rem;
	int income;

	while (scanf("%d", &F) != EOF && F) {
		income = 0;
		scanf("%d %d %d", &M, &N, &L);
		for (i = 0; i < L; i++) {
			scanf("%d %d %d %d %d %d %d",
					&jobs[i].c, &jobs[i].m,
					&jobs[i].t0, &jobs[i].t1,
					&jobs[i].v, &jobs[i].w, &jobs[i].x);
			jobs[i].status = jobs[i].early = 0;
		}
		qsort(jobs, L, sizeof(job), comp);
		curc = M, curm = N;
		for (t = 0; t < F; t++) {
			rec = rem = 0;
			for (i = 0; i < L; i++) {
				if (jobs[i].status)
					continue;
				else {
					if (jobs[i].t0 > t)
						break;
					if (jobs[i].c <= curc && jobs[i].m <= curm) {
						jobs[i].status = 1;
						jobs[i].early = jobs[i].t1 - t - 1;
						curc -= jobs[i].c, curm -= jobs[i].m;
						rec += jobs[i].c, rem += jobs[i].m;
					}
				}
			}
			curc += rec, curm += rem;
		}
		for (i = 0; i < L; i++) {
			if (jobs[i].status) {
				if (jobs[i].early >= 0)
					income += (jobs[i].v + jobs[i].early * jobs[i].w);
				else
					income += (jobs[i].v + jobs[i].early * jobs[i].x);
			}
			else if (jobs[i].t1 <= F)
				income += (jobs[i].t1 - F) * jobs[i].x;
		}
		printf("Case %d: %d\n\n", ++count, income);
	}
	return 0;
}
