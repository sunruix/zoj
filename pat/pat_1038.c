#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *a, const void *b)
{
	char *pa = (char *)a, *pb = (char *)b, sa[32], sb[32];

	strcpy(sa, pa), strcpy(sb, pb);
	strcat(sa, pb), strcat(sb, pa);
	return strcmp(sa, sb);
}

int main()
{
	int n, i, j;
	char s[10001][16];

	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);
	qsort(s, n, sizeof(s[0]), comp);
	for (i = 0; i < n; i++) {
		for (j = 0; s[i][j] != '\0' && s[i][j] == '0'; j++);
		if (s[i][j] != '\0')
			break;
	}
	if (i == n && s[i][j] == '\0')
		printf("0");
	else {
		printf("%s", s[i] + j);
		for (i++; i < n; i++)
			printf("%s", s[i]);
	}
	return 0;
}
