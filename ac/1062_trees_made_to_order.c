#include <stdio.h>
#define MAX 500000000

void print(int x, int a[32], int b[32])
{
	int i, ln, rn, l, r, offl, offr;

	if (!x)
		return;
	for (i = 0; b[i] <= x; i++);
	x -= b[i - 1] - 1; ln = 0; rn = i - 1 - ln - 1;
	while (x > a[ln] * a[rn])
		x -= a[ln] * a[rn], ln++, rn--;
	offl = x / a[rn], offr = x % a[rn];
	offr ? offr-- : ((offr = a[rn] - 1), offl ? offl-- : 0);
	l = b[ln] + offl, r = b[rn] + offr;
	if (l)
		printf("("), print(l, a, b), printf(")");
	printf("X");
	if (r)
		printf("("), print(r, a, b), printf(")");
}


int main()
{
	int n, i, j, a[32], b[32];

	a[0] = a[1] = 1, a[2] = 2, a[3] = 5;
	b[0] = 0, b[1] = 1, b[2] = 2, b[3] = 4;
	for (i = 4; a[i - 1] <= MAX; i++) {
		for (a[i] = j = 0; j <= i - 1; j++)
			a[i] += a[j] * a[i - j - 1];
		b[i] = b[i - 1] + a[i - 1];
	}
	while (scanf("%d", &n) != EOF && n)
		print(n, a, b), printf("\n");
	return 0;
}