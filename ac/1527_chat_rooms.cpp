#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#define isal(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z'))

using namespace std;

int check(const char *s, const char *al)
{
	int i, j, max;

	for (max = j = i = 0; s[i] != '\0'; i++)
		!isal(s[i]) || al[s[i]] ? (max = j > max ? j : max, j = 0) : j++;
	return max;
}

int main()
{
	int n, i, j, k;
	char al[128], line[256];
	string s;
	vector<string> sent;
	vector<int> status;

	memset(al, 0, sizeof(al));
	al['a'] = al['e'] = al['i'] = al['o'] = al['u'] = al['y'] = 1;
	al['A'] = al['E'] = al['I'] = al['O'] = al['U'] = al['Y'] = 1;
	while (scanf("%d\n", &n) != EOF) {
		sent.clear();
		status.clear();
		for (i = 0; i < n; i++) {
			fgets(line, sizeof(line), stdin);
			s = string(line);
			k = check(s.c_str(), al);
			if (k > 5) {
				printf("n\n");
				sent.push_back(s);
				status.push_back(1);
			}
			else if (k > 4) {
				vector<int>::iterator it;
				for (j = 0, it = status.begin(); it != status.end(); it++)
					if (*it == 1)
						j++;
				printf("%c\n", j > 2 ? 'n' : 'y');
				sent.push_back(s);
				status.push_back(1);
			}
			else {
				vector<string>::iterator it;
				for (j = 0, it = sent.begin(); it != sent.end(); it++)
					if (*it == s)
						j++;
				printf("%c\n", j > 1 ? 'n' : 'y');
				sent.push_back(s);
				status.push_back(0);
			}
			if (sent.size() > 10) {
				sent.erase(sent.begin());
				status.erase(status.begin());
			}
		}
	}
	return 0;
}