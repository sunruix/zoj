#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	char c;
	string w, s;
	map<string, string> M;

	while (cin >> s && s != "DICTIONARY_DEFINE_OVER") {
		if (s.length() > 3) {
			w = s;
			sort(s.begin() + 1, s.end() - 1);
			M[s] = w;
		}
	}
	s.clear();
	while ((c = getchar()) != '\n');
	while ((c = getchar()) != EOF) {
		if (isalpha(c))
			s += c;
		else {
			if (s.length() > 0) {
				if (s.length() > 3) {
					sort(s.begin() + 1, s.end() - 1);
					cout << M[s];
				}
				else
					cout << s;
				s.clear();
			}
			cout << c;
		}
	}
	return 0;
}