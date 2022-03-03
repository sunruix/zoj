#include <stdio.h>
#include <string.h>

int main()
{
	int i, p, N, t, l1, l2, ans;
	char s1[128], s2[128];

	scanf("%d", &N);
	while (N--) {
		scanf("%d", &t);
		gets(s1);
		gets(s1), gets(s2);
		l1 = strlen(s1), l2 = strlen(s2);
		for (i = 0; i < l1 && i < l2 && s1[i] == s2[i]; i++);
		ans = l1 + l2 - 2 * i;
		printf("%d\n", t * ans);
	}
	return 0;
}

