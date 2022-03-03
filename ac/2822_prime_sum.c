#include <stdio.h>
#include <math.h>

int isprime(int n) 
{
	int i, m;
	m = sqrt(n);
	for (i = 2; i <= m; i++)
		if (!(n % i))
			return 0;
	return 1;
}

int work(int n, int k, int prime[], int pnum, int p)
{
	int i;
	for (i = 0; i < pnum; p++)
		if (
int main()
{
	int n, k, a, i, j, prime[1024], pnum;
	freopen("input", "r", stdin);
	prime[0] = 2;
	for (i = 3, j = 1; i <= 1120; i += 2)
		if (isprime(i))
			prime[j++] = i;
	pnum = j;
	while (scanf("%d %d", &n, &k) != EOF && (n || k)) {
