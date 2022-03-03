#include <stdio.h>
#include <string.h>

typedef struct
{
	int t;
	int b;
	int l;
	int r;
	int visited;
	int same;
	int sp;
} square;

square array[30];
square *position[30];
int flag;

int comp(square a, square b)
{
	if (a.l != b.l || a.r != b.r ||
			a.t != b.t || a.b != b.b)
		return 0;
	return 1;
}

void check(int n, int N)
{
	if (n < N)
	{
		if (position[n]->l != position[n - 1]->r)
			flag = 0;
		return;
	}
	else if (n % N == 0)
	{
		if (position[n]->t != position[n - N]->b)
			flag = 0;
		return;
	}
	else
	{
		if (position[n]->l != position[n - 1]->r ||
				position[n]->t != position[n - N]->b)
			flag = 0;
		return;
	}
}

void put(int n, int N, int left)
{
	int i, j, p;

	flag = 1;
	p = N * N - left;
	array[n].visited = 1;
	position[p] = &array[n];
	left;
	if (p)
		check(p, N);
	if (!flag || !(left - 1))
	{
		array[n].visited = 0;
		return;
	}
	for (i = 0; i < N * N; i++)
	{
		if (array[i].visited || (array[i].same && array[array[i].sp].visited == 0))
			continue;
		put(i, N, left - 1);
		if (flag)
			break;
	}
	array[n].visited = 0;
}

int main()
{
	int N, i, j, count = 0;

	while (scanf("%d", &N) != EOF && N)
	{
		if (count) printf("\n");
		count++;
		for (i = 0; i < N * N; i++)
		{
			scanf("%d %d %d %d", &array[i].t, &array[i].r, &array[i].b, &array[i].l);
			array[i].visited = 0;
			array[i].same = 0;
			for (j = 0; j < i; j++)
				if (comp(array[i], array[j]))
				{
					array[i].same = 1;
					array[i].sp = j;
				}
		}
		for (i = 0; i < N * N; i++)
			array[i].visited = 0;
		for (i = 0; i < N * N; i++)
		{
			if (array[i].same)
				continue;
			put(i, N, N * N);
			if (flag)
				break;
		}
		if (flag)
			printf("Game %d: Possible\n", count);
		else
			printf("Game %d: Impossible\n", count);
	}
	return 0;
}

