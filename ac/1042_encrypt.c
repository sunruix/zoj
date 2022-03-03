#include <stdio.h>
#include <string.h>

void rote(char *s, char *t, int l, int k)
{
	int i;
	for (i = 0; i < l; i++)
		t[(i + k) % l] = s[i];
	t[l] = '\0';
}

int main()
{
	int k1, k2, k3, i, j1, j2, j3, l1, l2, l3;
	char s[128], s1[128], s2[128], s3[128], t1[128], t2[128], t3[128];

	while (scanf("%d %d %d", &k1, &k2, &k3) != EOF && (k1 || k2 || k3)) {
		j1 = j2 = j3 = 0;
		scanf("%s", s);
		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] >= 'a' && s[i] <= 'i')
				s1[j1++] = s[i];
			else if (s[i] >= 'j' && s[i] <= 'r')
				s2[j2++] = s[i];
			else
				s3[j3++] = s[i];
		}
		l1 = j1, l2 = j2, l3 = j3;
		rote(s1, t1, l1, k1);
		rote(s2, t2, l2, k2);
		rote(s3, t3, l3, k3);
		j1 = j2 = j3 = 0;
		for (i = 0; s[i] != '\0'; i++) {
			if (s[i] >= 'a' && s[i] <= 'i')
				s[i] = t1[j1++];
			else if (s[i] >= 'j' && s[i] <= 'r')
				s[i] = t2[j2++];
			else
				s[i] = t3[j3++];
		}
		printf("%s\n", s);
	}
	return 0;
}


