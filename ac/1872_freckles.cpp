#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#define dist(a, b, c, d) (((a) - (c)) * ((a) - (c)) + ((b) - (d)) * ((b) - (d)))

using namespace std;

struct edge {
	int v, w;
	double l;

	edge () {}
	edge (int vv, int ww, double ll)
	{
		v = vv, w = ww, l = ll;
	}
};

bool cmp(edge a, edge b)
{
	return a.l < b.l;
}

int find(int x, int s[])
{
	if (s[x] < 0)
		return x;
	return s[x] = find(s[x], s);
}

void setunion(int root1, int root2, int s[])
{
	if (s[root1] < s[root2])
		s[root1] -= s[root2], s[root2] = root1;
	else {
		if (s[root1] == s[root2])
			s[root2]--;
		s[root1] = root2;
	}
}

int main()
{
	int n, i, j, s[128], root1, root2;
	double node[128][2], ans;
	vector<edge> e;

	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%lf %lf", &node[i][0], &node[i][1]), s[i] = -1;
			for (j = 0; j < i; j++)
				e.push_back(edge(i, j, sqrt(dist(node[i][0], node[i][1], node[j][0], node[j][1]))));
		}
		sort(e.begin(), e.end(), cmp);
		ans = 0, i = 0;
		for (vector<edge> :: iterator it = e.begin(); it != e.end() && i < n - 1; it++) {
			if ((root1 = find(it->v, s)) != (root2 = find(it->w, s)))
				setunion(root1, root2, s), ans += it->l, i++;
		}
		e.clear();
		printf("%.2f\n", ans);
	}
	return 0;
}