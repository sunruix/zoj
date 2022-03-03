#include <stdio.h>

int main()
{
	int m, n, i, p, q;
	while(scanf("%d %d", &m, &n) != EOF && m && n) {
		if (m < n)
			p = m, m = n, n = p;
		i = 0;
		while ((p = m % n) && (m / n < 2)) {
			m = n;
			n = p;
			i++;
		}
		if (!(i % 2))
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}
