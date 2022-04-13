# include <stdio.h>
# include <string.h>

int main()
{
	int a, b, i, j, k;
	char s[128], t[128];

	scanf("%d %d", &a, &b);
	sprintf(s, "%d", a + b);
	for (i = strlen(s) - 1, j = 0, k = 1; i >= 0; i--, j++, k++) {
		t[j] = s[i];
		if (!(k % 3) && i >= 0 && (s[i - 1] >= '0' && s[i - 1] <= '9'))
			t[++j] = ',';
	}
	for (j--; j >= 0 ; j--)
		printf("%c", t[j]);
	printf("\n");
	return 0;
}
