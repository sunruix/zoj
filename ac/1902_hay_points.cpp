#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	int m, n, val, ans;
	string s, t;
	map<string, int> dic;

	while (cin >> m >> n) {
		while (m--) {
			cin >> s >> val;
			dic.insert(pair<string, int>(s, val));
		}
		while (n--) {
			ans = 0;
			while (cin >> t && t != ".")
				ans += dic[t];
			cout << ans << endl;
		}
	}
	return 0;
}