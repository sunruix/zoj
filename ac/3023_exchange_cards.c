#include <stdio.h>

typedef struct {
	int n, a[128], x;
} player;

player p1, p2;
int work (player *p1, player *p2, int sub)
{
	int i, j, sum;
	sum = 0x7fffffff;
	for (i = 1; i <= p1->n; i++)
		for (j = 1; j <= p2->n; j++)
			if (p1->a[i] - p2->a[j] == sub &&
					p1->a[i] + p2->a[j] < sum) {
				p1->x = p1->a[i], p2->x = p2->a[j];
				sum = p1->a[i] + p2->a[j];
			}
	if (sum == 0x7fffffff)
		return 0;
	return 1;
}

int main()
{
	int m, n, i, j, sum1, sum2, sub, res;

	while (scanf("%d %d", &m, &n) != EOF && (m || n)) {
		p1.n = m, p2.n = n;
		p1.x = p2.x = 0;
		sum1 = sum2 = 0;
		for (i = 1; i <= m; i++) {
			scanf("%d", &p1.a[i]);
			sum1 += p1.a[i];
		}
		for (j = 1; j <= n; j++) {
			scanf("%d", &p2.a[j]);
			sum2 += p2.a[j];
		}
		if (abs(sum1 - sum2) % 2) {
			printf("-1\n");
			continue;
		}
		sub = (sum1 - sum2) / 2;
		if (sub >= 0)
			res = work(&p1, &p2, sub);
		else
			res = work(&p2, &p1, -sub);
		if (res)
			printf("%d %d\n", p1.x, p2.x);
		else
			printf("-1\n");
	}
	return 0;
}
