#include <stdio.h>
#include <string.h>

int size(int n)
{
	if (n == 1)
		return 1;
	else
		return 3 * size(n - 1);
}

void setspace(int n, int i, int j, char g[][1024])
{
	int k, ii, jj;

	if (n == 1)
		g[i][j] = ' ';
	else {
		for (ii = i, k = size(n - 1); ii < i + 3 * k; ii += k)
			for (jj = j; jj < j + 3 * k; jj += k)
				setspace(n - 1, ii, jj, g);
	}
}

void setx(int n, int i, int j, char g[][1024])
{
	int k;

	if (n == 1)
		g[i][j] = 'X';
	else {
		k = size(n - 1);
		setx(n - 1, i, j, g), setspace(n - 1, i, j + k, g), setx(n - 1, i, j + k + k, g);
		setspace(n - 1, i + k, j, g), setx(n - 1, i + k, j + k, g), setspace(n - 1, i + k, j + k + k, g);
		setx(n - 1, i + k + k, j, g), setspace(n - 1, i + k + k, j + k, g), setx(n - 1, i + k + k, j + k + k, g);
	}
}

void print(int n, char g[][1024])
{
	int i, j, k;

	for (k = size(n), i = 0; i < k; i++) {
		for (j = k; g[i][j] != 'X' && j >= 0; j--);
		g[i][j + 1] = '\0';
		printf("%s", g[i]);
		printf("\n");
	}
}

int main()
{
	int n;
	char g[1024][1024];
	while (scanf("%d", &n) != EOF && n != -1) {
		memset(g, 0, sizeof(g));
		setx(n, 0, 0, g);
		print(n, g);
		printf("-\n");
	}
	return 0;
}