#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(char *a, char *b)
{
	for (int i = 0; i < 4; i++)
		if (a[i] != b[i])
			return a[i] < b[i];
	return true;
}

int main()
{
	int n, m, k, c, i, j;
	char stu[40000][5];
	vector<char *> cls[2501];

	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%s %d", &stu[i], &c);
		while (c--)
			scanf("%d", &j), cls[j].push_back(stu[i]);
	}
	for (i = 1; i <= m; i++) {
		printf("%d %d\n", i, cls[i].size());
		sort(cls[i].begin(), cls[i].end(), comp);
		for (vector<char *> :: iterator it = cls[i].begin(); it != cls[i].end(); it++)
			printf("%s\n", *it);
	}
	return 0;
}