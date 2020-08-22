#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}
char dic[120021][128];
int main()
{
	int n = 0, i, j, l;
	char w[128];

	while (scanf("%s", dic[n++]) != EOF);
	for (i = 0; i < n; i++) {
		l = strlen(dic[i]);
		for (j = 1; j < l; j++) {
			strncpy(w, dic[i], j);
			w[j] = '\0';
			if (bsearch(w, dic, n, sizeof(dic[0]), comp))
				if (bsearch(dic[i] + j, dic, n, sizeof(dic[0]), comp)) {
					printf("%s\n", dic[i]);
			//		break;
				}
		}
	}
	return 0;
}
