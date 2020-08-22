#include <stdio.h>
#include <string.h>

int main()
{
	int t, n, i, j, pos;
	char front[32], name[128][32];

	scanf("%d", &t);
	while (t--) {
		scanf("%d %s", &n, front);
		for (i = 0; i < n; i++) {
			scanf("%s", name[i]);
			if (!strcmp(front, name[i]))
				pos = i;
		}
		printf("%s\n", name[(pos + n / 2) % n]);
	}
	return 0;
}
