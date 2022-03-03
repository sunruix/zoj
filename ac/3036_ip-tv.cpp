#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

struct edge {
	int v, w, l;
	friend bool operator <(edge a, edge b) {
		return a.l > b.l;
	}
};

int find(int x, int *s)
{
	if (s[x] <= 0)
		return x;
	return s[x] = find(s[x], s);
}

void setunion(int root1, int root2, int *s)
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
	int t, n, m, s[2048], i, j, k, v, w, root1, root2, ans;
	string c1, c2;
	map<string, int> M;
	priority_queue<edge> q;
	edge temp;

	cin >> t;
	while (t--) {
		memset(s, 0, sizeof(s));
		cin >> n >> m;
		for (j = 1, i = 0; i < m; i++) {
			cin >> c1 >> c2 >> k;
			v = M[c1] ? M[c1] : (M[c1] = j, j++);
			w = M[c2] ? M[c2] : (M[c2] = j, j++);
			temp.v = v, temp.w = w, temp.l = k;
			q.push(temp);
		}
		for (ans = i = 0; i < n - 1; ) {
			temp = q.top(), q.pop();
			if ((root1 = find(temp.v, s)) != (root2 = find(temp.w, s)))
				ans += temp.l, setunion(root1, root2, s), i++;
		}
		while (!q.empty())
			q.pop();
		M.clear();
		cout << ans << endl;
	}
	return 0;
}