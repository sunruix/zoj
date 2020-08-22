#include <stdio.h>
#include <math.h>

int main()
{
	int n, Euler, i, j, k, fac[1024];
	while (scanf("%d", &n) != EOF && n) {
		Euler = n;
		for (i = 2, j = 0, k = sqrt(n); i <= k; i++) {
			if (!(n % i))
				fac[j++] = i;
			while(!(n % i))
				n /= i;
		}
		if (n != 1)
			fac[j++] = n;
		for (i = 0; i < j; i++)
			Euler -= Euler / fac[i];
		printf("%d\n", Euler);
	}
	return 0;
}
