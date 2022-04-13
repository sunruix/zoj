#include <iostream>
#include <string>
#include <map>

#define isalnum(c) (((c) >= 'a' && (c) <= 'z') || ((c) >= 'A' && (c) <= 'Z') || ((c) >= '0' && (c) <= '9'))
#define isupper(c) ((c) >= 'A' && (c) <= 'Z')

using namespace std;

int main() {
    map<string, int> dict;
    string s = "", t;
    freopen("input", "r", stdin);
    while (cin >> t)
        s += " " + t;
    int i = 0, j = 0, max = 0;
    while (1) {
        while (i < s.size() && !isalnum(s[i]))
            ++i;
        if (i >= s.size())
            break;
        for (j = i; j < s.size() && isalnum(s[j]); ++j) {
            if (isupper(s[j]))
               s[j] = s[j] - 'A' + 'a'; 
        }
        string word = string(s, i, j - i);
        map<string, int>::iterator it = dict.find(word);
        if (it == dict.end())
            dict[word] = 1;
        else
            dict[word] = dict[word] + 1;
        if (dict[word] > max)
            max = dict[word];
        i = j;
    }
    for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it)
        if (it->second == max) {
            cout << it->first << ' ' << it->second << endl;
            break;
        }
    return 0;
}
