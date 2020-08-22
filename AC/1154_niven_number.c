#include <stdio.h>
#include <string.h>

int main()
{
	int N, b, dsum, i;
	long long dec, t;
	char s[1024];

	scanf("%d", &N);
	while (N--) {
		getchar();
		while (scanf("%d", &b) != EOF && b) {
			scanf("%s", s);
			dsum = 0; dec = 0; t = 1; 
			for (i = strlen(s) - 1; i >= 0; i--) {
				dsum += s[i] - '0';
				dec += t * (s[i] - '0');
				t *= b;
			}
			if (!(dec % dsum))
				printf("yes\n");
			else
				printf("no\n");
		}
		if (N)
			printf("\n");
	}
	return 0;
}
