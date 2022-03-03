#include <stdio.h>

int main()
{
	int t, n, m, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d\n", &n);
		m = 1 - n;
		while (n--) {
			scanf("%d", &k);
			m += k;
		}
		printf("%d\n", m);
	}
	return 0;
}
