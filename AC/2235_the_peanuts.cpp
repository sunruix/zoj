#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
	int i, j, k;
} record;

bool comp(record a, record b)
{
	return a.k > b.k;
}

int main()
{
	int t, n, m, i, j, k, time, ans;
	record temp;
	vector<record> v;

	cin >> t;
	while (t--) {
		cin >> n >> m >> time;
		for (k = 0, i = 1; i <= n; i++)
			for (j = 1; j <= m; j++) {
				cin >> k;
				if (k)
					temp.i = i, temp.j = j, temp.k = k, v.push_back(temp);
			}
		sort(v.begin(), v.end(), comp);
		time -= v[0].i + 1, ans = 0;
		if (time >= v[0].i) {
			for (ans += v[0].k, i = 1; i < v.size(); i++) {
				time -= abs(v[i].i - v[i - 1].i) + abs(v[i].j - v[i - 1].j) + 1;
				if (time >= v[i].i)
					ans += v[i].k;
				else
					break;
			}
		}
		cout << ans << endl;
		v.clear();
	}
	return 0;
}
