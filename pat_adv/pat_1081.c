#include <stdio.h>

#define max(a, b) ((a) > (b) : (a) : (b))

typedef struct {
    long long num, denum;
} rational;

long long gcd(long long a, long long b) {
    long long r;
    while (r = a % b) {
        a = b;
        b = r;
    }
    return b;
}

void reduce(rational *a) {
    long long g = gcd(a->num, a->denum);
    a->num /= g;
    a->denum /= g;
}

void add(rational *a, rational *b) {
    a->num = a->num * b->denum + a->denum * b->num;
    a->denum *= b->denum;
    reduce(a);
}

int main() {
    int n;
    long long it, r, g;
    char s[128];
    rational a, b;
    freopen("input", "r", stdin);
    scanf("%d", &n);
    scanf("%ld/%ld", &a.num, &a.denum);
    while (--n) {
        scanf("%ld/%ld", &b.num, &b.denum);
        add(&a, &b);
    }
    reduce(&a);
    it = a.num / a.denum;
    r = a.num % a.denum;
    if (it)
        printf("%ld", it);
    if (r)
        printf("%s%ld/%ld", it ? " " : "", r, a.denum);
    else if (!it)
        printf("0");
    printf("\n");
    return 0;
}
