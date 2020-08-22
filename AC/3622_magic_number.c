#include <stdio.h>
#define max 0x7fffffffll

int main()
{
	long long n, m, i, j, k, a[64] = {1, 2, 5, 10, 20, 25, 50}, b[8] = {10, 8, 5, 4, 2};

	for (i = 7, j = 1000; j / 10 < max; j *= 10) {
		for (k = 0; k < 5; k++)
			a[i++] = j / b[k];
	}
	while (scanf("%lld %lld", &m, &n) != EOF) {
		for (j = 0; a[j] < m && j < i; j++);
		for (k = j; a[k] <= n && k < i; k++);
		printf("%lld\n", k - j);
	}
	return 0;
}