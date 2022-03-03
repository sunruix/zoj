#include <stdio.h>
#include <string.h>

/**
int main()
{
	int n, i, j, sum, a[128], m[2048];
	freopen("input.txt", "r", stdin);
	while (scanf("%d", &n) != EOF && n >= 0) {
		for (i = sum = 0; i < n; i++)
			scanf("%d", &a[i]), sum += a[i];
		memset(m, 0, sizeof(m));
		for (i = 0, m[0] = 1; i < n; i++)
			for (j = sum; j >= a[i]; j--)
				m[j] = m[j] || m[j - a[i]];
		for (i = sum % 2 ? sum - 1 : sum, m[0] = 0; i >= 0; i -= 2)
			if (m[i] && m[i / 2])
				break;
		if (i > 0)
			printf("%d\n", i / 2);
		else
			printf("Sorry\n");
	}
	return 0;
}
**/