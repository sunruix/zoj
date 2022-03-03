#include <stdio.h>
#include <string.h>

void add(char *res, char *t, char *s)
{
	int i, carry, temp;
	for (i = 510, carry = 0; i >= 0; i--) {
		temp = s[i] - '0' + t[i] - '0' + carry;
		carry = 0;
		if (temp >= 10) {
			temp -= 10;
			carry = 1;
		}
		res[i] = temp + '0';
	}
}

int main()
{
	int n, i, j;
	char count0[1024][512], count1[1024][512], one[512];
	memset(one, '0', sizeof(one));
	one[510] = '1';
	memset(count0, '0', sizeof(count0));
	memset(count1, '0', sizeof(count1));
	count0[2][510] = '1';
	for (i = 3; i <= 1000; i++) {
		add(count1[i], count0[i - 1], count1[i - 1]);
		add(count0[i], count0[i - 1], count1[i - 1]);
		if (!(i % 2))
			add(count0[i], one, count0[i]);
	}
	while (scanf("%d", &n) != EOF) {
		for (i = 0; count0[n][i] == '0' && i < 510; i++);
		for (;i < 511; i++)
			putchar(count0[n][i]);
		putchar('\n');
	}
	return 0;
}
