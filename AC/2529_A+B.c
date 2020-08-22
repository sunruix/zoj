/*************************************************************************
 Author: WilliamChang
 Created Time: 2011/12/7 20:06:52
 File Name: g:\Users\SR\Documents\acm\2529_A+B.c
 Description: 
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#include <string.h>

int isprime(int n)
{
	int i, m;
	for (i = 2, m = sqrt(n); i <= m; i++) if (!(n % i))
			return 0;
	return 1;
}

int main()
{
	int i, j, temp, carry, prime[128], ss[128], tt[128];
	char s[128], t[128];
	for (i = 2, j = 127; j >= 0; i++)
	   if (isprime(i))
		   prime[j--] = i;
	while (scanf("%s %s", s, t) != EOF) {
		memset(ss, 0, sizeof(ss));
		memset(tt, 0, sizeof(tt));
		for (i = strlen(s) - 1, j = 127, temp = 1; i >= 0; i--) {
			if (s[i] >= '0' && s[i] <= '9') {
				ss[j] = ss[j] + temp * (s[i] - '0');
				temp *= 10;
			}
			else
				j--, temp = 1;
		}
		for (i = strlen(t) - 1, j = 127, temp = 1; i >= 0; i--) {
			if (t[i] >= '0' && t[i] <= '9') {
				tt[j] = tt[j] + temp * (t[i] - '0');
				temp *= 10;
			}
			else
				j--, temp = 1;
		}
		for (i = 127, carry = 0; i >= 0; i--) {
			ss[i] += tt[i] + carry;
			carry = 0;
			if (ss[i] >= prime[i]) {
				ss[i] -= prime[i];
				carry = 1;
			}
		}
		for (i = 0; ss[i] == 0 && i < 127; i++);
		for (; i < 127; i++)
			printf("%d,", ss[i]);
		printf("%d\n", ss[i]);
	}
	return 0;
}

