#include <stdio.h>

int n, i, j, k, ans, mod[1024];
char name[1024][16], pswd[1024][16], *p;

int main()
{
	scanf("%d", &n);
	for (ans = i = 0; i < n; i++) {
		scanf("%s %s", name[i], pswd[i]);
		for (p = pswd[i]; *p; p++)
			if (*p == '1')
				*p = '@', mod[i] ? 0 : ((mod[i] = 1), ans++);
			else if (*p == '0')
				*p = '%', mod[i] ? 0 : ((mod[i] = 1), ans++);
			else if (*p == 'l')
				*p = 'L', mod[i] ? 0 : ((mod[i] = 1), ans++);
			else if (*p == 'O')
				*p = 'o', mod[i] ? 0 : ((mod[i] = 1), ans++);
	}
	if (!ans) {
		n == 1 ? printf("There is ") : printf("There are ");
		printf("%d %s and no account is modified", n, n == 1 ? "account" : "accounts");
	}
	else
		for (printf("%d\n", ans), i = 0; i < n; i++)
			mod[i] ? printf("%s %s\n", name[i], pswd[i]) : 0;
	return 0;
}

