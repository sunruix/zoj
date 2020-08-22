#include <stdio.h>
#include <string.h>

char dic[120001][64]; 

int main()
{
	int n, m, i, j, k, l1, l2, index[26][2];
	char *w1, *w2, c;
	freopen("input1", "r", stdin);
	for (i = 0; i < 26; i++)
		index[i][0] = 0, index[i][1] = -1;
	i = c = 0;
	while (scanf("%s", dic[i]) != EOF) {
		if (dic[i][0] != c) {
			index[dic[i][0] - 'a'][0] = i;
			if (c)
				index[c - 'a'][1] = i - 1;
			c = dic[i][0];
		}
		i++;
	}
	index[c - 'a'][1] = i - 1;
	n = i;
	for (i = 0; i < n; i++) {
		w1 = dic[i];
		l1 = strlen(w1);
		for (j = index[w1[0] - 'a'][0]; j <= index[w1[0] - 'a'][1]; j++) {
			if (j == i)
				continue;
			if (!strncmp(w1, dic[j], l1)) {
				w2 = dic[j] + l1;
				for (k = index[w2[0] - 'a'][0]; k <= index[w2[0] - 'a'][1]; k++)
					if (!strcmp(w2, dic[k]))
						printf("%s\n", dic[j]);
			}
		}
	}
	return 0;
}

