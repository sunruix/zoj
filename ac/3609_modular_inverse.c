#include <stdio.h>

int main()
{
	int t, a, m, i;

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &m);
		if (a == 1 || m == 1)
			printf("1\n");
		else {
			for (i = 1; i < m; i++)
				if (a * i % m == 1)
					break;
			if (i == m)
				printf("Not Exist\n");
			else
				printf("%d\n", i);
		}
	}
	return 0;
}