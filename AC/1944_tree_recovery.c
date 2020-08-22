#include <stdio.h>
#include <string.h>

void postorder(char *s1, int l1, int r1, char *s2, int l2, int r2)
{
	int i, j;

	if (l1 >= r1) {
		if (l1 == r1)
			printf("%c", s1[l1]);
		return;
	}
	for (i = l2, j = l1; s2[i] != s1[l1]; i++, j++);
	postorder(s1, l1 + 1, j, s2, l2, i - 1);
	postorder(s1, j + 1, r1, s2, i + 1, r2);
	printf("%c", s1[l1]);
}

int main()
{
	char s1[32], s2[32];

	while (scanf("%s %s", s1, s2) != EOF) {
		postorder(s1, 0, strlen(s1) - 1, s2, 0, strlen(s2) - 1);
		printf("\n");
	}
	return 0;
}