#include <stdio.h>

int prime[10000] = {2, 3, 5, 7}, end = 4;

int bprime(int n) {
    int i;
    if (n == 1)
        return 0;
    else if (n == 2 || n == 3 || n == 5 || n == 7)
        return 1;
    else if (!(n % 2 && n % 3 && n % 5 && n % 7))
        return 0;
    else {
        for (i = 0; i < end && n % prime[i]; ++i);
        return i == end ? prime[end++] = n : 0;
    }
}

int main() {
    int n, i, j, k, id, rank[10000] = {0}, checked[10000] = {0}, isprime[10000] = {0};
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &id);
        rank[id] = i;
        isprime[i] = bprime(i);
    }
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &id);
        printf("%04d: ", id);
        if (checked[id])
            printf("Checked\n");
        else {
            checked[id] = rank[id] && 1;
            if (!rank[id])
                printf("Are you kidding?\n");
            else if (1 == rank[id])
                printf("Mystery Award\n");
            else if (isprime[rank[id]])
                printf("Minion\n");
            else
                printf("Chocolate\n");
        }
    }
    return 0;
}
