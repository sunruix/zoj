#include <stdio.h>
#include <string.h>

int check1(char *s, int pos)
{
	int i, j, ans;

	for (i = pos - 1, j = pos + 1, ans = 1; s[i] == s[j] && i >= 0 && s[j] != '\0'; i--, j++)
			ans += 2;
	return ans;
}

int check2(char *s, int pos1, int pos2)
{
	int i, j, ans;
	
	for (i = pos1 - 1, j = pos2 + 1, ans = 2; s[i] == s[j] && i >= 0 && s[j] != '\0'; i--, j++)
		ans += 2;
	return ans;
}

int main()
{
	int i, j, k, l, ans = 0; 
	char s[1024];

	fgets(s, 1024, stdin);
	l = strlen(s);
	for (i = 0; i < l; i++)
		if ((k = check1(s, i)) > ans)
			ans = k;
	for (i = 0; i < l - 1; i++)
		if (s[i] == s[i + 1] && ((k = check2(s, i, i + 1)) > ans))
			ans = k;
	printf("%d", ans);
	return 0;
}

