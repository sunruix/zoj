#include <stdio.h>
#include <string.h>

typedef struct {
	int count;
	char name[64];
} record;

int main()
{
	int T, limit, n, m, i, j, k, r, min;
	char s[64], t[64];
	record rec[10001];

	scanf("%d", &T);
	for (r = k = 1; k <= T; k++, r = 1) {
		memset(rec, 0, sizeof(rec));
		scanf("%d %d %s %d", &limit, &n, &t, &i);
		rec[i].count = 1, strcpy(rec[i].name, t);
		while (--n) {
			scanf("%s %d", &s, &i);
			if (r && strcmp(s, t))
				r = 0;
			rec[i].count ? rec[i].count++ : (strcpy(rec[i].name, s), rec[i].count = 1);
		}
		printf("Case %d:\n", k);
		if (r) {
			for (i = 1; rec[i].count == 0 && i <= limit; i++);
			printf("The winner is %s.\nThe price is %d.\n", rec[i].name, i);
		}
		else {
			for (min = 0x7fffffff, i = 1; i <= limit; i++)
				if (rec[i].count && rec[i].count < min)
					min = rec[i].count, j = i;
			printf("The winner is %s.\nThe price is %d.\n", rec[j].name, j);
		}
		if (k < T)
			printf("\n");
	}
	return 0;
}