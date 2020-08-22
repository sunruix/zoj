#include <iostream>
#include <strstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct node {
    int id;
    vector<int> adj;

    friend bool operator< (const struct node& a, const struct node& b)
    {
        return a.adj.size() == b.adj.size() ? a.id < b.id : a.adj.size() < b.adj.size();
    }
};

void parse_t(string, struct node&);
void parse_s(string, struct node&);
int subt(string&);

vector<struct node> v;

int subt(string& s)
{
    int i, count = 1;
    for (i = 1; i < s.length() && count; ++i)
        if (s[i] == '(')
            ++count;
        else if (s[i] == ')')
            --count;
    return i;
}

void parse_t(string s, struct node& parent)
{
    struct node n;
    string ss = s.substr(1, s.length() - 2);
    istrstream is(ss.c_str());
    is >> n.id;
    ss.clear();
    getline(is, ss);
    if (parent.id) {
        parent.adj.push_back(n.id);
        n.adj.push_back(parent.id);
    }
    if (ss.length())
        parse_s(ss.substr(1), n);
    v.push_back(n);
}

void parse_s(string s, struct node& parent)
{
    int pos = subt(s);
    while ((pos = subt(s)) != s.length()) {
        parse_t(s.substr(0, pos), parent);
        s = s.substr(pos + 1);
    }
    parse_t(s.substr(0, pos), parent);
}

int main()
{
    string s;
    struct node r;
    r.id = 0;
    while (getline(cin, s)) {
        v.clear();
        parse_t(s, r);
        while (v.size() > 1) {
            sort(v.begin(), v.end());
            for (vector<struct node>::iterator it = v.begin() + 1; it != v.end(); ++it) {
                if (it->id == v.begin()->adj[0]) {
                    cout << it->id;
                    for (vector<int>::iterator itt = it->adj.begin(); itt != it->adj.end(); ++itt)
                        if (*itt == v.begin()->id) {
                            it->adj.erase(itt);
                            break;
                        }
                    break;
                }
            }
            v.erase(v.begin());
            if (v.size() > 1)
                cout << ' ';
        }
        cout << endl;
    }
    return 0;
}