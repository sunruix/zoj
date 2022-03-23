#include <stdio.h>
#include <math.h>

int prime[1000000], tab[1000000], mid = 46340, end;

int isprime(int n)
{
    int i;

    if ((n != 2 && !(n % 2)) || (n != 3 && !(n % 3)) || (n != 5 && !(n % 5)) || (n != 7 && !(n % 7)))
        return 0;
    for (i = 0; prime[i] * prime[i] <= n && i < end; i++)
        if (!(n % prime[i]))
            return 0;
    return 1;
}

int main()
{
    int l, u, i, j, p1, p2, p3, p4, min, max;

    for (prime[0] = 2, end = 1, i = 3; i < mid; i += 2)
        if (isprime(i))
            prime[end++] = i;
    while (scanf("%d %d", &l, &u) != EOF) {
        if (l > prime[end - 1]) {
            max = 0, min = 0x7fffffff;
            for (j = 0, i = l; i <= u && i > 0; i++)
                if (isprime(i)) {
                    tab[j] = i;
                    if (j) {
                        if (min > tab[j] - tab[j - 1])
                            min = tab[j] - tab[j - 1], p1 = tab[j - 1], p2 = tab[j];
                        if (max < tab[j] - tab[j - 1])
                            max = tab[j] - tab[j - 1], p3 = tab[j - 1], p4 = tab[j];
                    }
                    j++;
                }
        }
        else {
            if (u > prime[end - 1])
                for (i = prime[end - 1] + 2; i <= u; i += 2)
                    if (isprime(i))
                        prime[end++] = i;
            for (i = 0; prime[i] < l && i < end; i++);
            for (max = 0, min = 0x7fffffff, j = i + 1; prime[j] <= u && j < end; i++, j++) {
                if (min > prime[j] - prime[i])
                    min = prime[j] - prime[i], p1 = prime[i], p2 = prime[j];
                if (max < prime[j] - prime[i])
                    max = prime[j] - prime[i], p3 = prime[i], p4 = prime[j];
            }
        }
        if (!max)
            printf("There are no adjacent primes.\n");
        else
            printf("%d,%d are closest, %d,%d are most distant.\n", p1, p2, p3, p4);
    }
    return 0;
}

