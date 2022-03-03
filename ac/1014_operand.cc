#include <cstdio>
#include <vector>
#include <cctype>
#include <iostream>
#include <strstream>

using namespace std;

int priority[256];

int bracket_len(const string& s)
{
    int count = 1, i = 1;
    for (i = 1; i < s.length() && count != 0; ++i) {
        if (s[i] == '(')
            ++count;
        else if (s[i] == ')')
            --count;
    }
    return i;
}

string divide(string exp, int part) {
    int i = 0;
    char lowest = '^';
    vector<int> pos;
    if (exp.c_str()[0] == '(')
        if ((i = bracket_len(exp)) == exp.length())
            return exp.substr(1, exp.length() - 2);
    while (i < exp.length()) {
        if (exp[i] == '(')
            i += bracket_len(exp.substr(i));
        if (!isalpha(exp[i])) {
            if (priority[exp[i]] == priority[lowest])
                pos.push_back(i);
            else if (priority[exp[i]] > priority[lowest]) {
                lowest = exp[i];
                pos.clear();
                pos.push_back(i);
            }
        }
        ++i;
    }
    pos.push_back(exp.length());
    return part == 1 ? exp.substr(0, pos[0]) : exp.substr(pos[part - 2] + 1, pos[part - 1] - pos[part - 2] - 1);
}

int main()
{
    freopen("input", "r", stdin);
    string exp, ques, left, right;
    int n, x;
    bool first_time = true;
    priority['^'] = 0; priority['*'] = 1; priority['+'] = 2;
    while (cin >> exp && exp[0] != '*') {
        printf("%s %c:\n", first_time ? "Expression" : "\nExpression", exp[0]);
        first_time = false;
        scanf("%d\n", &n);
        //cin >> n;
        for (int i = 0; i < n; ++i) {
            getline(cin, ques);
            istrstream num_in(ques.c_str());
            left = exp[0];
            right = exp.substr(3, exp.length() - 3);
            while (num_in >> x) {
                left = "op(" + to_string(x) + "," + left + ")";
                right = divide(right, x);
            }
            cout << left << "=" << right << endl;
        }
    }
    return 0; 
}
