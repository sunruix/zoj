#include <stdio.h>
#include <string.h>
#define max 2000000
#define mod 1000000

int m[max + 1];

int main()
{
	int t, n, i, j;

	memset(m, 0, sizeof(m));
	for (i = 2; i < max; i <<= 1)
		for (m[i]++, j = 0; j <= max - i; j++)
			m[j + i] = (m[j + i] % mod + m[j] % mod) % mod;
	for (i = 1; i <= max; i++)
		m[i] = (m[i] % mod + m[i - 1]) % mod;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", m[n] + 1);
	}
	return 0;
}