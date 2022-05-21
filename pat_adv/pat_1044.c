#include <stdio.h>

int a[100000], s[100000], e[100000];

int main()
{
	int n, m, i, j, k, sum, min, p, start, temp;

	scanf("%d %d", &n, &m);
	for (min = 100000000, sum = p = 0, start = i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		if (sum >= m) {
			for (temp = sum, j = start; temp >= m; j++)
				temp -= a[j];
			temp += a[--j];
			if (temp <= min) {
				temp < min ? (min = temp, p = 0) : 0;
				s[p] = j, e[p++] = i;
			}
			sum -= a[start++];
		}
	}
	for (i = 0; i < p; i++)
		printf("%d-%d\n", s[i], e[i]);
	return 0;
}
