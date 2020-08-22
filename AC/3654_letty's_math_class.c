#include <stdio.h>
#include <ctype.h>

int main()
{
	int i, j;
	long long a, b, ans;
	char s[1024];
	freopen("input.txt", "r", stdin);
	while (scanf("%s", &s) != EOF) {
		for (j = 1, ans = i = 0; s[i] != '\0'; i++) {
			if (isdigit(s[i])) {
				a = s[i] - '0';
				while (isdigit(s[++i]))
					a = a * 10 + s[i] - '0';
				ans += j * a, i--;
			}
			else
				j = s[i] == '+' ? 1 : -1;
		}
		scanf("%lld %lld", &a, &b);
		printf("%c\n", a == 9 || (ans != a && b != 9) ? 'A' : 'B');
	}
	return 0;
}
