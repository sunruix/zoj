#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, k, m[1024];

	memset(m, 0, sizeof(m));
	for (i = 2; i <= 17; i++)
		for (k = i * i, m[k]++, j = 0; j < 300; j++)
			m[j + k] += m[j];
	for (i = 1; i < 300; i++)
		m[i] += m[i - 1];
	while (scanf("%d", &n) != EOF && n)
		printf("%d\n", m[n] + 1);
	return 0;
}
