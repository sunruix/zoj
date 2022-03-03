#include <stdio.h>

int main()
{
	int m, n, i;
	char pre, c;

	scanf("%d", &m);
	while (m--) {
		scanf("%d\n", &n), pre = 0, i = 0;
		while (n)
			if ((c = getchar()) == 'U' || c == 'D') {
				n--;
				c != pre ? pre = c, i++ : 0;
			}
		printf("%d\n", i - 1);
		m ? printf("\n") : 0;
	}
	return 0;
}