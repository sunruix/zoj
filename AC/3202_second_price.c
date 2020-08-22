#include <stdio.h>

int main()
{
	int T, N, a[128], i, max, second, p;

	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		max = second = p = 0;
		for (i = 1; i <= N; i++) {
			scanf("%d", &a[i]);
			if (max < a[i]) {
				max = a[i];
				p = i;
			}
		}
		for (i = 1; i <= N; i++)
			if (second < a[i] && a[i] != max)
				second = a[i];
		printf("%d %d\n", p, second);
	}
	return 0;
}
