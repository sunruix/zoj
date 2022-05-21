#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double pos, price;
} station;

int comp(const void *a, const void *b)
{
	station *pa = (station *)a, *pb = (station *)b;
	return pa->pos > pb->pos ? 1 : -1;
}

int main()
{
	int n, i, j, k;
	double cap, l, mile, cost, left;
	station st[505];

	scanf("%lf %lf %lf %d", &cap, &l, &mile, &n);
	cap *= mile;
	for (i = 0; i < n; i++)
		scanf("%lf %lf", &st[i].price, &st[i].pos);
	st[n].pos = l, st[n++].price = 0;
	qsort(st, n, sizeof(station), comp);
	i = 0, left = cost = 0;
	while (i < n - 1) {
		if (st[i + 1].pos - st[i].pos > cap)
			break;
		for (j = i + 1; st[j].pos - st[i].pos <= cap; j++) {
			if (st[j].price <= st[i].price) {
				if (st[j].pos - st[i].pos <= left)
					left -= st[j].pos - st[i].pos;
				else {
					cost += st[i].price * (st[j].pos - st[i].pos - left);
					left = 0;
				}
				i = j; break;		
			}
		}
		if (i != j) {
			cost += st[i].price * (cap - left);
			left = cap - (st[i + 1].pos - st[i].pos);
			i = i + 1;
		}
	}
	if (i == n - 1)
		printf("%.2f\n", cost / mile);
	else if (st[0].pos < 0.01)
		printf("The maximum travel distance = %.2f\n", (double)(st[i].pos + cap));
	else
		printf("The maximum travel distance = 0.00\n");
	return 0;
}