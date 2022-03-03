#include <stdio.h>
#include <math.h>

int sum(int n)
{
	int ans = 0;
	while (n)
		ans += n % 10, n /= 10;
	return ans;
}

int main()
{
	int n, m, i, j, s, t;

	while (scanf("%d", &n) != EOF && n) {
		while (++n) {
			s = sum(n), t = 0;
			for (i = 2, m = n; i <= sqrt(m); i++) {
				if (m % i)
					continue;
				while (!(m % i))
					t += sum(i), m /= i;
			}
			if (m == n)
				continue;
			if (m != 1)
				t += sum(m);
			if (t == s)
				break;
		}
		printf("%d\n", n);
	}
	return 0;
}

