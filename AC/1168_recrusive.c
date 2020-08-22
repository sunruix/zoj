#include <stdio.h>
#include <string.h>

int m[32][32][32];
int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a < 21 && b < 21 && c < 21 && m[a][b][c])
		return m[a][b][c];
	if (a > 20 || b > 20 || c > 20)
		return w(20, 20, 20);
	if (a < b && b < c)
		return m[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return m[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) +
			w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
	int a, b, c;
	memset(m, 0, sizeof(m));
	while (scanf("%d %d %d", &a, &b, &c) != EOF && (a != -1 || b != -1 || c != -1))
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	return 0;
}
