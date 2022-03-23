#include <stdio.h>

typedef struct {
	char id[8];
	int A, C, M, E;
} record;

int main()
{
	int m, n, i, j, rank[4], best_course[2048], best_rank[2048];
	char query[8], map[4] = {'A', 'C', 'M', 'E'}; 
	record rec[2048];

	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		scanf("%s", rec[i].id);
		scanf("%d %d %d", &rec[i].C, &rec[i].M, &rec[i].E);
		rec[i].A = (rec[i].C + rec[i].M + rec[i].E) / 3;
	}
	for (i = 0; i < m; i++) {
		rank[0] = rank[1] = rank[2] = rank[3] = 1;
		for (j = 0; j < m; j++) {
			if (j == i)
				continue;
			if (rec[j].A > rec[i].A)
				rank[0]++;
			if (rec[j].C > rec[i].C)
				rank[1]++;
			if (rec[j].M > rec[i].M)
				rank[2]++;
			if (rec[j].E > rec[i].E)
				rank[3]++;
		}
		for (j = 0, best_rank[i] = m; j < 4; j++)
			if (rank[j] < best_rank[i]) {
				best_course[i] = j;
				best_rank[i] = rank[j];
			}
	}

	for (i = 0; i < n; i++) {
		scanf("%s", query);
		for (j = 0; j < m; j++) {
			if (!strcmp(query, rec[j].id)) {
				printf("%d %c\n", best_rank[j], map[best_course[j]]);
				break;
			}
		}
		if (j == m)
			printf("N/A\n");
	}
	return 0;
}
