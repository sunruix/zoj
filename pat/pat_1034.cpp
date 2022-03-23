#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[4];
	int time;
} record;

typedef struct {
	char name[4];
	int num;
} answer;

int comp(const void *a, const void *b)
{
	answer *pa = (answer *)a, *pb = (answer *)b;
	return strcmp(pa->name, pb->name);
}

record rec[2002];
answer ans[2002];
int sum, num, max, head, m, visited[2002], adj[2002][2002];

void dfs(int v)
{
	int w;
	visited[v] = 1;
	sum += rec[v].time, num++;
	if (max < rec[v].time)
		max = rec[v].time, head = v;
	for (w = 0; w < m; w++)
		if (adj[v][w] && !visited[w])
			dfs(w);
}

int main()
{
	int n, min, a, i, j, k, v, w;
	char s[4], t[4];

	scanf("%d %d", &n, &min);
	for (i = m = 0; i < n; i++) {
		v = w = -1;
		scanf("%s %s %d", s, t, &a);
		for (j = 0; j < m && strcmp(s, rec[j].name); j++);
		if (j == m)
			v = m++, strcpy(rec[v].name, s);
		else
			v = j;
		for (j = 0; j < m && strcmp(t, rec[j].name); j++);
		if (j == m)
			w = m++, strcpy(rec[w].name, t);
		else
			w = j;
		adj[v][w] = adj[w][v] = 1;
		rec[v].time += a, rec[w].time += a;
	}
	for (i = j = 0; i < m; i++) {
		if (!visited[i]) {
			sum = max = num = 0;
			dfs(i);
			if (num > 2 && sum / 2 > min)
				strcpy(ans[j].name, rec[head].name), ans[j++].num = num;
		}
	}
	qsort(ans, j, sizeof(answer), comp);
	printf("%d\n", j);
	for (i = 0; i < j; i++)
		printf("%s %d\n", ans[i].name, ans[i].num);
	return 0;
}