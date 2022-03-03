#include <stdio.h>
#include <string.h>

int main()
{
	int n, m, i, j, k, l, min, ans;
	char s[10001], c;

	scanf("%d", &n);
	while (n--) {
		scanf("%s", &s);
		for (l = strlen(s), c = 'z' + 1, i = 0; s[i] != '\0'; i++) {
			if (c > s[i])
				c = s[i], k = 1;
			else if (c == s[i])
				k++;
		}
		if (k == l)
			printf("1\n");
		else {
			for (ans = i = 0; s[i] != '\0'; i++)
				if (s[i] == c) {
					for (j = ans, k = i, m = 0; m < l; j = (j + 1) % l, k = (k + 1) % l, m++)
						if (s[j] != s[k]) {
							if (s[j] > s[k])
								ans = i;
							break;
						}
				}
			printf("%d\n", ans + 1);
		}
	}
	return 0;
}