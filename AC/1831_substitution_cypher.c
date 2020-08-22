#include <stdio.h>
#include <string.h>

int main()
{
	int i, j;
	char a[128], b[128], s[128], map[128];

	while (fgets(a, sizeof(a), stdin) && fgets(b, sizeof(b), stdin)) {
		memset(map, 0, sizeof(map));
		for (i = 0; a[i] != '\0'; i++)
			map[a[i]] = b[i];
		printf("%s%s", b, a);
		while (fgets(s, sizeof(s), stdin)) {
			for (i = 0; s[i] != '\0'; i++)
				map[s[i]] ? s[i] = map[s[i]] : 0;
			printf("%s", s);
		}
	}
	return 0;
}