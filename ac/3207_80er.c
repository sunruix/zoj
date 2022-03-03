#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

int main() {
	int n, k, i, ans;
	char dic[128][32], key[32];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", dic[i]);
	qsort(dic, n, sizeof(dic[0]), comp);
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &i);
		ans = 0;
		while (i--) {
			scanf("%s", key);
			if (bsearch(key, dic, n, sizeof(dic[0]), comp))
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
