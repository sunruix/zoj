#include <stdio.h>
#include <string.h>

int main()
{
	int N, i, j, flag, count;
	char name[16], p[16], c, rname[1024][16], rp[1024][16];

	while (scanf("%d", &N) != EOF && N) {
		count = 0;
		for (i = 0; i < N; i++) {
			scanf("%s %s", name, p);
			flag = 0;
			for (j = 0; p[j] != '\0'; j++) {
				if (p[j] == '0') {
					flag = 1;
					p[j] = '%';
				}
				else if (p[j] == '1') {
					flag = 1;
					p[j] = '@';
				}
				else if (p[j] == 'l') {
					flag = 1;
					p[j] = 'L';
				}
				else if (p[j] == 'O') {
					flag = 1;
					p[j] = 'o';
				}
			}
			if (flag) {
				strcpy(rname[count], name);
				strcpy(rp[count++], p);
			}
		}
		if (count) {
			printf("%d\n", count);
			for (i = 0; i < count; i++)
				printf("%s %s\n", rname[i], rp[i]);
		}
		else
			printf("No account is modified.\n");
	}
	return 0;
}
