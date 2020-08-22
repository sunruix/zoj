#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

struct edge {
	int v, w;
	double len;
	friend bool operator <(edge a, edge b) {
		return a.len > b.len;
	}
};

double len(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int find (int x, int s[])
{
	if (s[x] <= 0)
		return x;
	return s[x] = find(s[x], s);
}

void setUnion(int root1, int root2, int s[])
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
	int N, i, j, s[128], root1, root2, count;
	double cor[128][2], ans;
	edge temp;
	priority_queue <edge> Q;

	count = 0;
	while (scanf("%d", &N) != EOF && N) {
		memset(s, 0, sizeof(s));
		for (i = 1; i <= N; i++) {
			scanf("%lf %lf", &cor[i][0], &cor[i][1]);
			for (j = 1; j < i; j++) {
				temp.v = i, temp.w = j;
				temp.len = len(cor[i][0], cor[i][1], cor[j][0], cor[j][1]);
				Q.push(temp);
			}
		}
		ans = 0, i = 0;
		while (i < N - 1) {
			temp = Q.top(), Q.pop();
			root1 = find(temp.v, s), root2 = find(temp.w, s);
			if (root1 != root2) {
				ans += temp.len;
				setUnion(root1, root2, s);
				i++;
			}
		}
		if (count++)
			printf("\n");
		printf("Case #%d:\n", count);
		printf("The minimal distance is: %.2f\n", ans);
		while (Q.size())
			Q.pop();
	}
	return 0;
}