#include <stdio.h>
#include <string.h>

int main()
{
	int t, i, j, hasport, haspath, count;
	char s[64], proto[64], host[64], port[64], path[64];

	scanf("%d\n", &t), count = 1;
	while (t--) {
		strcpy(port, "<default>");
		strcpy(path, "<default>");
		scanf("%[^:]://%s\n", proto, s);
		for (i = j = 0; s[i] != '\0' && s[i] != ':' && s[i] != '/'; i++, j++)
			host[j] = s[i];
		host[j] = '\0';
		if (s[i] == ':') {
			for (++i, j = 0; s[i] != '\0' && s[i] != '/'; i++, j++)
				port[j] = s[i];
			port[j] = '\0';
		}
		if (s[i] == '/') {
			for (++i, j = 0; s[i] != '\0'; i++, j++)
				path[j] = s[i];
			path[j] = '\0';
		}
		printf("URL #%d\n", count++);
		printf("Protocol = %s\n", proto);
		printf("Host     = %s\n", host);
		printf("Port     = %s\n", port);
		printf("Path     = %s\n\n", path);
	}
	return 0;
}