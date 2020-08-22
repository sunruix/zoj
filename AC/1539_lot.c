#include <stdio.h>

int f(int n)
{
	if (n == 3)
		return 1;
	if (n < 3)
		return 0;
	if (n & 1)
		return f(n >> 1) + f((n >> 1) + 1);
	return
		f(n >> 1) << 1;
}

int main()
{
	int n;

	while (scanf("%d", &n) != EOF)
		printf("%d\n", f(n));
	return 0;
}