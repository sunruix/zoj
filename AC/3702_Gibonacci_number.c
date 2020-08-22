#include <stdio.h>

int main()
{
	int T, i, j, k, gi, f[32];

	scanf("%d", &T);
	for (f[0] = f[1] = 1, i = 2; i < 32; i++)
		f[i] = f[i - 1] + f[i - 2];
	while (T--) {
		scanf("%d %d %d", &i, &gi, &j);
		if (gi < f[i] || (gi - f[i]) % f[i - 1])
			printf("-1\n");
		else {
			k = (gi - f[i]) / f[i - 1];
			printf("%lld\n", (long long)f[j] + (long long)k * (long long)f[j - 1]);
		}
	}
	return 0;
}