#include <stdio.h>
#include <string.h>

int main()
{
	int sum, i;
	char s[1024];
	memset(s, 0, sizeof(s));
	while (scanf("%s", s) != EOF && strcmp(s, "0")) {
		while (1) {
			sum = 0;
			for (i = 0; s[i] != '\0'; i++)
				sum += s[i] - '0';
			memset(s, 0, sizeof(s));
			if (sum < 10) {
				printf("%d\n", sum);
				break;
			}
			else 
				sprintf(s, "%d", sum);
		}
	}
	return 0;
}
