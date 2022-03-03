#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int main()
{
	int n = 0, i, j, count = 1, ans;
	char s[8][16], t[16];

	while (scanf("%s", t) != EOF) {
		if (strcmp(t, "9"))
			strcpy(s[n++], t);
		else {
			qsort(s, n, sizeof(s[0]), comp);
			for (i = 0, ans = 1; i < n && ans; i++)
				for (j = strlen(s[i]) - 1; j > 0 && ans; j--) {
					strncpy(t, s[i], j), t[j] = '\0';
					if (bsearch(t, s, n, sizeof(s[0]), comp))
						ans = 0;
				}
			printf("Set %d is ", count++);
			if (!ans)
				printf("not ");
			printf("immediately decodable\n");
			n = 0;
		}
	}
	return 0;
}
			