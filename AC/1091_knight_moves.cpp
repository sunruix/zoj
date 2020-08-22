#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
	int i, j, k, ii, jj, ans, mov[16][16];
	const int dir[8][2] = {-2, -1, -2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2};
	char c1, c2;
	pair<int, int> from, to;
	queue< pair<int, int> > Q;

	while (scanf("%c%d %c%d\n", &c1, &i, &c2, &j) != EOF) {
		memset(mov, 0, sizeof(mov));
		from = pair<int, int>(c1 - 'a' + 1, i);
		to = pair<int, int>(c2 - 'a' + 1, j);
		if (from == to)
			ans = 0;
		else {
			Q.push(from);
			while (!Q.empty()) {
				i = Q.front().first, j = Q.front().second, Q.pop();
				for (k = 0; k < 8; k++) {
					ii = i + dir[k][0], jj = j + dir[k][1];
					if (ii == to.first && jj == to.second) {
						ans = mov[i][j] + 1;
						while (!Q.empty())
							Q.pop();
						break;
					}
					if (ii > 0 && ii <= 8 && jj > 0 && jj <= 8)
						if (!mov[ii][jj] && (ii != from.first || jj != from.second)) {
							Q.push(pair<int, int>(ii, jj));
							mov[ii][jj] = mov[i][j] + 1;
						}
				}
			}
		}
		printf("To get from %c%d to %c%d takes %d knight moves.\n", c1, from.second, c2, to.second, ans);
	}
	return 0;
}