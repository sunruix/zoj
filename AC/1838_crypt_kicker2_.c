#include <stdio.h>
#include <string.h>

int getline(char *s)
{
	char c;
	int i = 0;
	while ((c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	s[i] = '\0';
	if (i || c == '\n')
		return i;
	return -1;
}

void decrypt(char *line, char *map)
{
	int i;
	for (i = 0; line[i] != '\0'; i++) {
		if (line[i] != ' ')
			line[i] = map[line[i] - 'a'];
	}
}

int main()
{
	int i, j, l, ll, n = 0, flag = 0;
	char c, c1, c2, lines[128][128], map[32];
	const char *dog = "the quick brown fox jumps over the lazy dog\0";

	freopen("input1", "r", stdin);
	ll = strlen(dog);
	while ((l = getline(lines[n++])) >= 0) {
		if (!l) {
			if (!flag) {
				printf("No solution.\n");
				continue;
			}
			for (i = 0; i < n; i++) {
				decrypt(lines[i], map);
				printf("%s\n", lines[i]);
			}
			n = 0;
			continue;
		}
		if (!flag && l == ll) {
			memset(map, 0, sizeof(map));
			for (i = 0; i < l; i++) {
				c1 = lines[n - 1][i], c2 = dog[i];
				if ((c1 == ' ' && c2 != ' ') || (c1 != ' ' && c2 == ' '))
					break;
				else if (c1 == ' ' && c2 == ' ')
					continue;
				if (map[c1 - 'a'] != 0 && map[c1 - 'a'] != c2)
					break;
				else
					map[c1 - 'a'] = c2;
			}
			if (i == l)
				flag = 1;
		}
	}
	return 0;
}

