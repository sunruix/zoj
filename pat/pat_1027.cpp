#include <stdio.h>

void convert(int n, char *s)
{
	int a, b;
	a = n / 13, b = n % 13;
	s[0] = a > 9 ? a - 10 + 'A' : a + '0';
	s[1] = b > 9 ? b - 10 + 'A' : b + '0';
	s[2] = 0;
}

int main()
{
	int a, b, c;
	char sa[3], sb[3], sc[3];

	scanf("%d %d %d", &a, &b, &c);
	convert(a, sa), convert(b, sb), convert(c, sc);
	printf("#%s%s%s", sa, sb, sc);
	return 0;
}