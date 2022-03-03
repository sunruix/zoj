#include <stdio.h>
#include <string.h>

int main()
{
	int n, i, j, temp;
	char s[32768], t[32768], ans[32768];

	scanf("%d", &n);
	while (n--) {
		scanf("%s %s", s, t);
		for (i = j = 0; s[i] != '\0' && t[i] != '\0'; i++) {
			temp = s[i] - '0' + t[i] - '0' + j;
			j = 0;
			if (temp > 9)
				j = 1, temp -= 10;
			ans[i] = temp + '0';
		}
		if (t[i] == '\0') {
			for (; s[i] != '\0'; i++) {
				temp = s[i] - '0' + j;
				j = 0;
				if (temp > 9)
					j = 1, temp -= 10;
				ans[i] = temp + '0';
			}
		}
		else {
			for (; t[i] != '\0'; i++) {
				temp = t[i] - '0' + j;
				j = 0;
				if (temp > 9)
					j = 1, temp -= 10;
				ans[i] = temp + '0';
			}
		}
		if (j)
			ans[i++] = '1';
		ans[i] = '\0';
		for (i = 0; ans[i] == '0'; i++);
		printf("%s\n", ans + i);
	}
	return 0;
}