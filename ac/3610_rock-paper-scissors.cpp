#include <stdio.h>

int main()
{
	int T;
	char s[32], t[32], x[32];
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%s %s %s", s, t, x);
			printf("%s will survive\n", t);
	}
	return 0;
}