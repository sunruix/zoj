#include <stdio.h>

int main()
{
	int t, m, n, i, j, count, a[100001], b[100001];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &m);
		for (i = 0; i < m; i++)
			scanf("%d", &a[i]);
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &b[i]);
		for (i = 0, j = 0, count = 0; i < m && j < n;) {
			if (a[i] != b[j]) {
				if (a[i] < b[j])
					i++;
				else
					j++;
			}
			else
				i++, j++, count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
