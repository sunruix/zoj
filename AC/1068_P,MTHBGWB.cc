#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
    map<char, string> m1;
    map<string, char> m2;
    string morse[32] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                        "....", "..", ".---", "-.-", ".-..", "--", "-.",
                        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                        "...-", ".--", "-..-", "-.--", "--.."};
    for (int i = 0; i < 26; ++i) {
        m1['A' + i] = morse[i];
        m2[morse[i]] = 'A' + i;
    }
    m1['_'] = "..--", m2["..--"] = '_';
    m1[','] = ".-.-", m2[".-.-"] = ',';
    m1['.'] = "---.", m2["---."] = '.';
    m1['?'] = "----", m2["----"] = '?';

    int n;
    freopen("input", "r", stdin);
    cin >> n;
    for (int t = 1; t <= n; ++t) {
        char buf[128] = {0};
        int num[128] = {0};
        string dots = "";
        cin >> buf;
        for (int i = 0; buf[i] != '\0'; ++i) {
            num[i] = m1[buf[i]].length();
            dots += m1[buf[i]];
        }
        cout << t << ": ";
        for (int i = strlen(buf) - 1, j = 0; i >= 0; --i) {
            cout << m2[dots.substr(j, num[i])];
            j += num[i];
        }
        cout << endl;
    }
    return 0;
}