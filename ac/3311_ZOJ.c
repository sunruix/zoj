#include <stdio.h>
#include <string.h>

int check1(char *s, int z, int j)
{
	int head, tail;
	if (j - z != 2)
		return 0;
	head = z, tail = strlen(s) - 1 - j;
	if (tail - head != 1)
		return 0;
	return 1;
}

int check2(char *s, int z, int j)
{
	int a, b, c;
	char t[128];
	a = z, b = j - z - 2, c = strlen(s) - j - 2;
	if (b > c || a >= c)
		return 0;
	strncpy(t, s, j - 1);
	t[j - 1] = '\0';
	strcat(t, s + j);
	t[strlen(t) - 1] = '\0';
	if (check1(t, z, j - 1))
		return 1;
	return
		check2(t, z, j - 1);
}

int main()
{
	int z, o, j, i, a, b, c, ac;
	char s[128], cc;

	while (scanf("%s", s) != EOF) {
		z = j = -1, ac = 1;
		for (i = 0; s[i] != '\0' && ac; i++) {
			if (s[i] == 'Z') {
				if (z == -1)
					z = i;
				else
					ac = 0;
			}
			else if (s[i] == 'J') {
				if (j == -1)
					j = i;
				else
					ac = 0;
			}
		}
		if (!ac || z > j || z < 0 || j < 0)
			printf("Wrong Answer\n");
		else {
			if (check1(s, z, j) || check2(s, z, j))
				printf("Accepted\n");
			else
				printf("Wrong Answer\n");
		}
	}
	return 0;
}

