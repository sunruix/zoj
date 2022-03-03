#include <stdio.h>
#include <string.h>

void div8(char *s, char *res)
{
	int i, j, k;
	int divee, val, r;

	divee = r = i = j = 0;
	while (1) {
		if (s[i] == '\0' && r == 0)
			break;
		else if (s[i])
			divee = r * 10 + s[i] - '0';
		else
			divee = r * 10;
		val = divee / 8;
		if (val || i)
			res[j++] = val + '0';
		r = divee % 8;
		i++;
	}
}

int main()
{
	int i, j, k, end;
	char s[4096], t[12288];

	while (scanf("%s", s) != EOF) {
		if (!strcmp(s, "1"))
			printf("1 [8] = 1 [10]\n");
		else if (!strcmp(s, "0"))
			printf("0 [8] = 0 [10]\n");
		else {
			memset(t, 0, sizeof(t));
			i = strlen(s) - 1;
			end = 3 * (i - 1) - 1;
			for (;s[i] == '0'; i--);
			for (j = 0; s[i] != '.'; i--, j++) {
				k = end - 3 * j;
				t[k] = s[i];
				div8(t + k, t + (end - 3 * (j + 1) + 1));
			}
			printf("%s [8] = 0.%s [10]\n", s, t);
		}
	}
	return 0;
}
