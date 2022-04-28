#include <stdio.h>

typedef struct {
    long long num, denom, integer;
} rational;

void add(rational *a, rational *b, rational *c) {
    c->num = a->num * b->denom + a->denom * b->num;
    c->denom = a->denom * b->denom;
}

void diff(rational *a, rational *b, rational *c) {
    c->num = a->num * b->denom - a->denom * b->num;
    c->denom = a->denom * b->denom;
}

void multi(rational *a, rational *b, rational *c) {
    c->num = a->num * b->num;
    c->denom = a->denom * b->denom;
}

void divide(rational *a, rational *b, rational *c) {
    c->num = a->num * b->denom;
    c->denom = a->denom * b->num;
    if (b->num < 0) {
        c->denom = -(c->denom);
        c->num = -(c->num);
    }
}

long long gcd(long long a, long long b) {
    long long r;
    while (r = a % b) {
        a = b;
        b = r;
    }
    return b > 0 ? b : -b;
}

void reduce(rational *a) {
    long long g = gcd(a->num, a->denom);
    a->num /= g;
    a->denom /= g;
    a->integer = a->num / a->denom;
    a->num %= a->denom;
    if (a->integer < 0)
        a->num = -(a->num);
}

void format(rational *a, char *s) {
    rational b = *a;
    if (b.denom == 0) {
        sprintf(s, "Inf");
        return;
    }
    reduce(&b);
    if (0 == b.integer) {
        if (0 == b.num)
            sprintf(s, "0");
        else
            b.num > 0 ?  sprintf(s, "%ld/%ld", b.num, b.denom) : sprintf(s, "(%ld/%ld)", b.num, b.denom);
    }
    else {
        if (b.integer < 0)
            b.num ? sprintf(s, "(%ld %ld/%ld)", b.integer, b.num, b.denom) : sprintf(s, "(%ld)", b.integer);
        else
            b.num ? sprintf(s, "%ld %ld/%ld", b.integer, b.num, b.denom) : sprintf(s, "%ld", b.integer);
    }
}

int main() {
    int i;
    rational a, b, c;
    char sa[32] = {0}, sb[32] = {0}, sc[32] = {0}, opc[4] = {'+', '-', '*', '/'};
    void (*op[4])() = {add, diff, multi, divide};
    freopen("input", "r", stdin);
    a.integer = b.integer = c.integer = 0;
    scanf("%ld/%ld %ld/%ld", &a.num, &a.denom, &b.num, &b.denom);
    format(&a, sa);
    format(&b, sb);
    for (i = 0; i < 4; ++i) {
        op[i](&a, &b, &c);
        format(&c, sc);
        printf("%s %c %s = %s\n", sa, opc[i], sb, sc);
    }
    return 0;
}
