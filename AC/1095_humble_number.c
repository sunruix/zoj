#include <stdio.h>

int fac[4] = {2, 3, 5, 7};
long long list[8192];
int make(long long n, int k)
{
	int i, j2, j3, j5, j7, p;
	for (i = 1; i < 8192; i++) {
		for (j = 0; j < 4; j++)
			for (j2 = j; j2 < 4; j++)

	return 0;
}

int main()
{
	int n, j;
	long long i;
	list[1] = 1;
	for (i = 2, j = 2; i <= 2000000000; i++)
		if (check(i, j))
			list[j++] = i;
	while (scanf("%d", &n) != EOF && n)
		printf("%d\n", list[n]);
	return 0;
}
