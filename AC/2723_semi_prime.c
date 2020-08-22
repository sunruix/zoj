#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, n, m, flag;

	while (scanf("%d", &n) != EOF && n) {
		m = sqrt(n), flag = 0;
		for (i = 2; i <= m; i++) {
			if (!(n % i)) {
				if (flag == 1) {
					flag = 0;
					break;
				}
				n /= i;
				m = sqrt(n);
				i = 1;
				flag = 1;
			}
		}
		if (flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
