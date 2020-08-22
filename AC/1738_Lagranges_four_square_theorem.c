#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, k, l, a[256], ans[32768];
	
	memset(ans, 0, sizeof(ans));
	for (i = 0, j = 1; j * j < 32768; j++)
		a[i++] = j * j;
	for (n = i, i = 0; i < n; i++)
		for (ans[a[i]]++, j = i; j < n && a[i] + a[j] < 32768; j++)
			for (ans[a[i] + a[j]]++, k = j; k < n && a[i] + a[j] + a[k] < 32768; k++)
				for (ans[a[i] + a[j] + a[k]]++, l = k; l < n && a[i] + a[j] + a[k] + a[l] < 32768; l++)
					ans[a[i] + a[j] + a[k] + a[l]]++;
	while (scanf("%d", &n) != EOF && n)
		printf("%d\n", ans[n]);
	return 0;
}