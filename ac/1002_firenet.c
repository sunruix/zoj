#include <stdio.h>

char map[4][5];
int count;
int max;

void input(int n)
{
	int i = 0;

	while (i < n)
		scanf("%s", map[i++]);
}

int check(int x, int y, int n)
{
	int i, j;

	if (map[x][y] != '.')
		return 0;

	i = x;
	j = y;
	while (--j >= 0 && map[i][j] != 'X')
		if (map[i][j] == 'o')
			return 0;
	j = y;
	while (++j < n && map[i][j] != 'X')
		if (map[i][j] == 'o')
			return 0;

	i = x;
	j = y;
	while (--i >= 0 && map[i][j] != 'X')
		if (map[i][j] == 'o')
			return 0;
	while (++i < n && map[i][j] != 'X')
		if (map[i][j] == 'o')
			return 0;
	return 1;
}

int complete(int n)
{
	int i, j;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (check(i, j, n))
				return 0;
	return 1;
}


void compute(int n)
{
	int i, j;

	if (complete(n))
	{
		if (count > max)
			max = count;
		return ;
	}

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (check(i, j, n))
			{
				map[i][j] = 'o';
				count++;
				compute(n);
				count--;
				map[i][j] = '.';
			}
		}
}

int main()
{
	int N;

	while (scanf("%d", &N) != EOF && N)
	{
		count = max = 0;
		input(N);
		compute(N);
		printf("%d\n", max);
	}
	return 0;
}
