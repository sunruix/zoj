#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int v, adjnum;
	int adj[10001];
} node;

typedef struct {
	int top;
	int array[10001];
} *stack;

void push(int x, stack s)
{
	s->array[++s->top] = x;
}

int pop(stack s)
{
	return s->array[s->top--];
}

node N[10001];
stack s;
int deep[10001], visited[10001], degree[10001], dpst[10001];

int dfs(int x)
{
	int v, w, i, max = 0;
	push(x, s);
	deep[x] = 0;
	while (s->top >= 0) {
		v = pop(s);
		visited[v] = 1;
		for (i = 0; i < N[v].adjnum; i++) {
			w = N[v].adj[i];
			if (!visited[w]) {
				push(w, s);
				deep[w] = deep[v] + 1;
				if (deep[w] > max)
					max = deep[w];
			}
		}
	}
	return max;
}

int main()
{
	int n, i, j, k, v, w;
	int max = 0, count = 0;
	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (i = 0; i < n - 1; i++) {
		scanf("%d %d", &v, &w);
		N[v].adj[N[v].adjnum++] = w;
		N[w].adj[N[w].adjnum++] = v;
		degree[v]++, degree[w]++;
	}
	s = malloc(sizeof(*s));
	s->top = -1;
	for (i = 1; i <= n; i++)
		if (!visited[i]) {
			count++;
			dfs(i);
		}
	if (count > 1) {
		printf("Error: %d components\n", count);
		return 0;
	}
	for (i = 1; i <= n; i++) {
		if (degree[i] != 1)
			continue;
		memset(visited, 0, sizeof(visited));
		dpst[i] = dfs(i);
		if (max < dpst[i])
			max = dpst[i];
	}
	for (i = 1; i <= n; i++)
		if (dpst[i] == max)
			printf("%d\n", i);
	return 0;
}
