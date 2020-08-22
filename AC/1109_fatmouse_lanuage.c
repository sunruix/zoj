#include <stdio.h>
#include <string.h>

typedef struct {
	char s[16], t[16];
} dic;

int comp(const void *a, const void *b)
{
	dic *d1, *d2;
	d1 = (dic *)a, d2 = (dic *)b;
	return strcmp(d1->t, d2->t);
}

int main()
{
	int i, j;
	dic dd, *p, d[100005];

	for (i = 0; ; i++) {
		for (j = 0; (d[i].s[j] = getchar()) != ' ' && d[i].s[j] != '\n'; j++);
		if (j == 0)
			break;
		d[i].s[j] = '\0';
		for (j = 0; (d[i].t[j] = getchar()) != '\n'; j++);
		d[i].t[j] = '\0';
	}
	qsort(d, i, sizeof(dic), comp);
	while (scanf("%s", dd.t) != EOF) {
		if (p = (dic *)bsearch(&dd, d, i, sizeof(dic), comp))
			printf("%s\n", p->s);
		else
			printf("eh\n");
	}
	return 0;
}

