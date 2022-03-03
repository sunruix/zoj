#include <stdio.h>

int main()
{
	int mile, sum = 0;
	char tag, s[128];
	while (1) {
		scanf("%s", s);
		if (!strcmp(s, "#"))
			return 0;
		else if (!strcmp(s, "0")) {
			printf("%d\n", sum);
			sum = 0;
			continue;
		}
		scanf("%s %d %c", s, &mile, &tag);
		if (tag == 'F')
			sum += 2 * mile;
		else if (tag == 'B')
			sum += mile + mile / 2;
		else {
			if (mile >= 1 && mile <= 500)
				sum += 500;
			else
				sum += mile;
		}
	}
	return 0;
}
