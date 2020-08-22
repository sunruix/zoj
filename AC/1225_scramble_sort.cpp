#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int compn(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int compw(const void *a, const void *b)
{
	int i, j, na, nb;
	char *sa = (char *)a, *sb = (char *)b;

	for (i = 0; sa[i] != '\0' && sb[i] != '\0'; i++) {
		na = isupper(sa[i]) ? sa[i] - 'A' : sa[i] - 'a';
		nb = isupper(sb[i]) ? sb[i] - 'A' : sb[i] - 'a';
		if (na != nb)
			return na < nb ? -1 : 1;
	}
	if (sa[i] == '\0' && sb[i] == '\0')
		return 0;
	return
		sa[i] == '\0' ? -1 : 1;
}

int main()
{
	int n, m, i, j, k, l, pw, pn, num[2048], map[2048];
	char s[2048 * 32], t[32], word[2048][32];

	memset(s, 0, sizeof(s));
	while (gets(s) && strcmp(s, ".")) {
		for (n = m = pw = pn = 0; s[m] != '\0'; n++) {
			sscanf(s + m, "%s", t);
			l = strlen(t), m += l + 1;
			if (t[0] == '-' || (t[0] >= '0' && t[0] <= '9'))
				sscanf(t, "%d", &num[pn++]), map[n] = 0;
			else
				strcpy(word[pw], t), word[pw++][l - 1] = '\0', map[n] = 1;
		}
		qsort(num, pn, sizeof(num[0]), compn);
		qsort(word, pw, sizeof(word[0]), compw);
		for (i = j = k = 0; i < n - 1 && j < pn && k < pw; i++) {
			if (!map[i])
				printf("%d, ", num[j++]);
			else
				printf("%s, ", word[k++]);
		}
		if (j == pn) {
			while (k < pw - 1)
				printf("%s, ", word[k++]);
			printf("%s.\n", word[k]);
		}
		else {
			while (j < pn - 1)
				printf("%d, ", num[j++]);
			printf("%d.\n", num[j]);
		}
		memset(s, 0, sizeof(s));
	}
	return 0;
}
