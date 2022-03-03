#include <stdio.h>
#include <stdlib.h>
#define max 0x7fffffffffffffff

int main()
{
	long long v[3], p[3][2], i, j, n, *ans;
	
	while (scanf("%lld %lld %lld %lld", &v[0], &v[1], &v[2], &n) != EOF) {
		ans = (long long *)malloc(n * sizeof(long long));
		for (i = 0; i < 3; i++)
			p[i][0] = 0, p[i][1] = v[i];
		for (i = 0; i < n; i++) {
			for (ans[i] = max, j = 0; j < 3; j++)
				if (ans[i] > p[j][1])
					ans[i] = p[j][1];
			for (j = 0; j < 3; j++)
				if (p[j][1] <= ans[i])
					p[j][1] = v[j] * ans[p[j][0]++];
		}
		printf("%lld\n", ans[n - 1]), free(ans);
	}
	return 0;
}
				
