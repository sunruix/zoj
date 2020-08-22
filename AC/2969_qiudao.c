#include <stdio.h>

int main()
{
	int t, n, i, e, coe[1024];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i <= n; i++) {
			scanf("%d", &e);
			coe[i] = e * (n - i);
		}
		for (i = 0; i < n - 1; i++)
			printf("%d ", coe[i]);
		printf("%d\n", coe[i]);
	}
	return 0;
}
