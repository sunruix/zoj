#include <stdio.h>

int GCD(int m, int n)
{
	int p;
	while (p = m % n) {
		m = n;
		n = p;
	}
	return n;
}

int main()
{
	int N, M, m, n, lcm, temp;
	scanf("%d", &N);
	while (N--) {
		m = 0;
		scanf("%d", &M);
		if (M == 1) {
			scanf("%d", &lcm);
			printf("%d\n", lcm);
			continue;
		}
		while (M--) {
			scanf("%d", &n);
			if (!m) {
				m = n;
				continue;
			}
			if (m < n) {
				temp = m;
				m = n;
				n = temp;
			}
			lcm = (m / GCD(m, n)) * n;
			m = lcm;
		}
		printf("%d\n", lcm);
	}
	return 0;
}
