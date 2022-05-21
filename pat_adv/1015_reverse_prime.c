#include <stdio.h>
#include <math.h>

int isprime(int n)
{
	int i, k;
	k = sqrt(n);
	for (i = 2; i <= k; i++)
		if (!(n % i))
			return 0;
	return 1;
}

int work(int n, int d)
{
	int a[32], num = 0;
	int i, j, k;
	i = 0;
	while (n) {
		a[i++] = n % d;
		n = n / d;
	}
	for (j = 0; j < i; j++)
		num = num * d + a[j];
	return num;
}

int main()
{
	int N, D, R;

	while (scanf("%d", &N) != EOF && N >= 0) {
		scanf("%d", &D);
		R = work(N, D);
		if (N != 1 && isprime(N) &&
				R != 1 && isprime(R))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
