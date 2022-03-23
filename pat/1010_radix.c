#include <stdio.h>

const long long MAX = 0x7fffffffffffffffLL;

long long convert(const char *n, long long radix)
{
	int i;
	long long num = 0, c;

	for (i = 0; n[i] != '\0'; i++) {
		if (n[i] >= '0' && n[i] <= '9')
			c = n[i] - '0';
		else
			c = n[i] - 'a' + 10;
		if ((MAX - c) / radix < num)
			return MAX;
		else
			num = c + num * radix;
	}
	return num;
}

long long check(long long m1, const char *n)
{
	int i;
	long long left = 2, right = MAX, mid, temp = 0;
	long long m2;

	for (i = 0; n[i] != '\0'; i++) {
		if (n[i] >= '0' && n[i] <= '9') {
			if (n[i] - '0' >= left)
				left = n[i] - '0' + 1;
		}
		else
			if (n[i] - 'a' + 10 >= left)
				left = n[i] - 'a' + 10 + 1;
	}
	while (left >= 0 && right >= 0 && left <= right) {
		mid = left + (right - left) / 2;
		m2 = convert(n, mid);
		if (m2 == m1) {
			temp = mid;
			right = mid - 1;
		}
		else if (m2 > m1)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return temp;
}

int main()
{
	char N[2][16];
	int tag, mytag;
	long long a, b, radix;

	scanf("%s %s %d %Ld", N[0], N[1], &tag, &radix);
	mytag = (tag + 1) % 2;
	a = convert(N[mytag], radix);
	if (b = check(a, N[!mytag]))
		printf("%Ld\n", b);
	else
		printf("Impossible\n");
	return 0;
}
