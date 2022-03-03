#include <stdio.h>
#include <string.h>

int N, M, s[1024 * 512];

int find (int x)
{
	if (s[x] <= 0)
		return x;
	return s[x] = find(s[x]);
}

void setunion(int root1, int root2)
{
	if (s[root1] < s[root2])
		s[root2] = root1;
	else {
		if (s[root1] == s[root2])
			s[root2]--;
		s[root1] = root2;
	}
}

int main()
{
	int i, v, w, root1, root2, ans;

	while (scanf("%d %d", &N, &M) != EOF && (N || M)) {
		memset(s, 0, sizeof(s));
		ans = 1;
		if (M != N - 1)
			ans = 0;
		for (i = 0; i < M; i++) {
			scanf("%d %d", &v, &w);
			if (!ans)
				continue;
			root1 = find(v), root2 = find(w);
			if (root1 == root2)
				ans = 0;
			else
				setunion(root1, root2);
		}
		if (ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
