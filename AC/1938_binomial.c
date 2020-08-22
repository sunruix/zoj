#include <stdio.h>

int main()
{
	int n, k, i;
	double up, down;

	while (scanf("%d %d", &n, &k) != EOF && (n || k)) {
		if (k < n / 2)
			k = n - k;
		for (i = n, up = 1; i >= (k + 1); i--)
			up *= i;
		for (i = 1, down = 1; i <= (n - k); i++)
			down *= i;
		printf("%Ld\n", (long long)(up / down));
	}
	return 0;
}
