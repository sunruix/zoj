#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char s[8];
int map[32][32][32][16];
vector<int> cla[2500 * 201];

int main()
{
	int n, m, i, j, k, index, stu, c0, c1, c2, c3;
	
	scanf("%d %d", &n, &m);
	for (stu = i = 0; i < m; i++) {
		scanf("%d %d", &index, &k);
		while (k--) {
			scanf("%s", s);
			c0 = s[0] - 'A', c1 = s[1] - 'A', c2 = s[2] - 'A', c3 = s[3] - '0';
			if (!map[c0][c1][c2][c3])
				map[c0][c1][c2][c3] = ++stu;
			cla[map[c0][c1][c2][c3]].push_back(index);
		}
	}
	for (i = 0; i < n; i++) {
		scanf("%s", s);
		stu = map[s[0] - 'A'][s[1] - 'A'][s[2] - 'A'][s[3] - '0'];
		sort(cla[stu].begin(), cla[stu].end());
		printf("%s", s);
		printf(" %d", cla[stu].size());
		for (vector<int> :: iterator it = cla[stu].begin(); it != cla[stu].end(); it++)
			printf(" %d", *it);
		printf("\n");
	}
	return 0;
}

