#include <stdio.h>

int main()
{
	int i = 1, sum = 0;
	char c;

	freopen("input", "r", stdin);
	while ((c = getchar()) != EOF && c != '#') {
		if (c == '\n') {
			printf("%d\n", sum);
			sum = 0, i = 0;
		}
		else if (c != ' ')
			sum += i * (c - 'A' + 1);
		i++;
	}
	return 0;
}
