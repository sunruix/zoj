#include <stdio.h>

int main()
{
	int n1, n2, t, ans, i;
	char c, ab[8];
	scanf("%d", &t);
	while (t--) {
		ans = 1;
		scanf("%d\n", &n1);
		i = 0;
		while ((c = getchar()) != '\n')
			if (c >= 'A' && c <= 'Z')
				ab[i++] = c;
		scanf("%d\n", &n2);
		i = 0;
		while ((c = getchar()) != '\n')
			if (c >= 'A' && c <= 'Z')
				if (c != ab[i++])
					ans = 0;
		if (ans == 0 || n1 != n2)
			printf("DIFFERENT\n");
		else
			printf("SAME\n");
	}
	return 0;
}

