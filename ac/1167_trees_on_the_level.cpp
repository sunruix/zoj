#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
	int ele, pos;
	friend bool operator <(node a, node b) {
		return a.pos < b.pos;
	}
};

int main()
{
	int n = 0, i, j, k, err;
	char s[32768], t[512];
	node temp;
	vector<node> v;

	while (scanf("%s", s) != EOF) {
		if (s[0] == '(' && s[1] == ')') {
			sort(v.begin(), v.end()), err = 0;
			for (vector<node>::const_iterator i = v.begin(); i < v.end(); i++) {
				if (i != v.begin() && i->pos == (i - 1)->pos) {
					err = 1;
					break;
				}
				temp.pos = i->pos / 2;
				if (temp.pos && !binary_search(v.begin(), v.end(), temp)) {
					err = 1;
					break;
				}
			}
			if (err)
				printf("not complete\n");
			else {
				for (vector<node>::const_iterator i = v.begin(); i < v.end() - 1; i++)
					printf("%d ", i->ele);
				if (v.size());
					printf("%d\n", (v.back()).ele);
			}
			v.clear();
		}
		else {
			t[0] = s[strlen(s) - 1] = '\0';
			sscanf(s + 1, "%d,%s", &i, t);
			for (j = 0, k = 1; t[j] != '\0'; j++)
				k = 2 * k + (t[j] == 'R' ? 1 : 0);
			temp.ele = i, temp.pos = k;
			v.push_back(temp);
		}
	}
	return 0;
}