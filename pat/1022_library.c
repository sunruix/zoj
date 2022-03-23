#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char words[64];
	int num, index[8];
} keywords;

typedef struct {
	char array[6][81];
	keywords kw;
} record;
int comp(const void *a, const void *b)
{
	record *r1, *r2;
	r1 = (record *)a, r2 = (record *)b;
	return strcmp(r1->array[0], r2->array[0]);
}

int query(record r, char *s, int m)
{
	return !strcmp(r.array[m], s);
}

int q3(record r, char *s)
{
	int i, l;
	l = strlen(s);
	for (i = 1; i <= r.kw.num; i++)
		if (!strncmp(s, r.kw.words + r.kw.index[i], l))
			return 1;
	return 0;
}

int main()
{
	int n, q, m, i, j, k, nf;
	char s[81];
	record R[10001];

	scanf("%d\n", &n);
	for (i = 0; i < n; i++) {
		gets(R[i].array[0]);
		gets(R[i].array[1]);
		gets(R[i].array[2]);
		gets(R[i].kw.words);
		R[i].kw.num = 1;
		R[i].kw.index[1] = 0;
		for (j = 0; R[i].kw.words[j] != '\0'; j++)
			if (R[i].kw.words[j] == ' ') {
				R[i].kw.index[++R[i].kw.num] = j + 1;
			}
		gets(R[i].array[4]);
		gets(R[i].array[5]);
	}
	qsort(R, n, sizeof(record), comp);
	scanf("%d", &q);
	while (q--) {
		nf = 1;
		scanf("%d: ", &m);
		gets(s);
		printf("%d: %s\n", m, s);
		for (i = 0, nf = 1; i < n; i++) {
			if (m == 3) {
				if (q3(R[i], s)) {
					puts(R[i].array[0]);
					nf = 0;
				}
			}
			else if (query(R[i], s, m)) {
				puts(R[i].array[0]);
				nf = 0;
			}
		}
		if (nf)
			printf("Not Found\n");

	}
	return 0;
}
