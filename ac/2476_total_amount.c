#include <stdio.h>
#include <string.h>

int main()
{
	int N, i, j, k, temp, sum, z, p;
	char s[16], a[32], b[32];
	freopen("input", "r", stdin);
	while (scanf("%d", &N) != EOF && N) {
		sum = 0;
		while (N--) {
			scanf("%s", s);
			temp = 0;
			for (i = 1; s[i] != '\0'; i++)
				if (s[i] >= '0' && s[i] <= '9')
					temp = 10 * temp + (s[i] - '0');
			sum += temp;
		}
		if (sum < 100) {
			printf("$0.%02d\n", sum);
			continue;
		}
		printf("$");
		z = sum / 100;
		for (i = 31, k = 1; z != 0; z /= 10, k++) {
			b[i--] = z % 10 + '0';
			if (!(k % 3) && z >= 10)
				b[i--] = ',';
		}
		for (j = i + 1; j <= 31; j++)
			printf("%c", b[j]);
		printf(".%02d\n", sum % 100);
	}
	return 0;
}
