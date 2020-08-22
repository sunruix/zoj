#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int check (char *s, char *t)
{
	int i, maps[26], mapt[26];

	memset(maps, 0, sizeof(maps));
	memset(mapt, 0, sizeof(mapt));
	for (i = 0; s[i] != '\0'; i++)
		maps[s[i] - 'a']++, mapt[t[i] - 'a']++;
	for (i = 0; i < 26; i++)
		if (maps[i] != mapt[i])
			return 0;
	return 1;
}

int main()
{
	int i, j, n, ans;
	char dic[128][8], s[8];

	while (scanf("%s", s) != EOF) {
		for (i = 0; strcmp(s, "XXXXXX"); i++)
			strcpy(dic[i], s), scanf("%s", s);
		qsort(dic, i, sizeof(dic[0]), comp);
		while (scanf("%s", s) != EOF && strcmp(s, "XXXXXX")) {
			for (j = 0, ans = 0; j < i; j++)
				if (strlen(dic[j]) == strlen(s))
					if (check(dic[j], s))
						printf("%s\n", dic[j]), ans = 1;
			if (!ans)
				printf("NOT A VALID WORD\n");
			printf("******\n");
		}
	}
	return 0;
}
