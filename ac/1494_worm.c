#include <stdio.h>

int main()
{
	int n, u, d, h, i;
	while (scanf("%d %d %d", &n, &u, &d) != EOF && (n || u || d)) {
		for (i = 0, h = 0; h < n; i++) {
			if (!(i % 2))
				h += u;
			else
				h -= d;
		}
		printf("%d\n", i);
	}
	return 0;
}

int main()
{
	int n, u, d, temp;
	while (scanf("%d %d %d", &n, &u, &d) != EOF && n) {
		temp = (n - u) % (u - d) == 0 ? (n - u) / (u - d) : (n - u) / (u - d) + 1;
		printf("%d\n", temp * 2 + 1);
	}
	return 0;
}
