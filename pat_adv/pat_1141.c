#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char stu[8], school[8];
    double score;
} rec1;

typedef struct {
    int tws, ns;
    double dtws;
    char *school;
} rec2;

int cmp1(const void *a, const void *b) {
    rec1 *pa = (rec1 *)a, *pb = (rec1 *)b;
    if (!strcmp(pa->school, pb->school))
        return strcmp(pa->stu, pb->stu);
    return strcmp(pa->school, pb->school);
}

int cmp2(const void *a, const void *b) {
    rec2 *pa = (rec2 *)a, *pb = (rec2 *)b;
    if (pa->tws == pb->tws) {
        if (pa->ns == pb->ns)
            return strcmp(pa->school, pb->school);
        return pa->ns - pb->ns;
    }
    return pb->tws - pa->tws;
}

int main() {
    int n, i, j, k, m;
    char level;
    rec1 a[100000];
    rec2 rank[100000];
    freopen("input", "r", stdin);
    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        scanf("%c%s %lf %s\n", &level, a[i].stu, &a[i].score, a[i].school);
        a[i].score = level == 'B' ? a[i].score / 1.5 : (level == 'T' ? a[i].score * 1.5 : a[i].score);
        for (j = 0; a[i].school[j] != '\0'; ++j)
            if (a[i].school[j] >= 'A' && a[i].school[j] <= 'Z')
                a[i].school[j] += 'a' - 'A';
    }
    qsort(a, n, sizeof(rec1), cmp1);
    memset(rank, 0, sizeof(rank));
    rank[k = 0].school = a[0].school;
    rank[k].ns = 1;
    rank[k].dtws = a[0].score;
    for (i = 1; i < n; ++i) {
        if (strcmp(a[i].school, rank[k].school)) {
            rank[k].tws = (int)rank[k].dtws;
            ++k;
            rank[k].school = a[i].school;
        }
        rank[k].dtws += a[i].score;
        if (strcmp(a[i].stu, a[i - 1].stu))
            ++rank[k].ns;
    }
    rank[k].tws = (int)rank[k].dtws;
    ++k;
    qsort(rank, k, sizeof(rec2), cmp2);
    printf("%d\n", k);
    for (m = -1, i = 0; i < k; ++i) {
        if (rank[i].tws != m) {
            m = rank[i].tws;
            j = i + 1;
        }
        printf("%d %s %d %d\n", j, rank[i].school, rank[i].tws, rank[i].ns);
    }
    return 0;
}

/*** this code also works ***/
/*
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct {
    int b, a, t, tws, ns;
    string school;
} record;

bool cmp(const record &a, const record &b) {
    if (a.tws == b.tws) {
        if (a.ns == b. ns)
            return a.school < b.school;
        return a.ns < b.ns;
    }
    return a.tws > b.tws;
}

int main () {
    int n;
    map<string, record> list;
    map<string, int> students;
    vector<record> ans;
    freopen("input", "r", stdin);
    cin >> n;
    while (n--) {
        int score;
        char level;
        string stuid, school;
        cin >> level >> stuid >> score >> school;
        for (int i = 0; i < school.length(); ++i)
            if (school[i] >= 'A' && school[i] <= 'Z')
                school[i] = school[i] - 'A' + 'a';
        map<string, record>::iterator it = list.find(school);
        if (it == list.end()) {
            record r;
            r.a = r.b = r.t = 0;
            int &sc = level == 'A' ? r.a : (level == 'B' ? r.b : r.t);
            sc = score;
            r.ns = 1;
            students[stuid] = 1;
            list[school] = r;
        }
        else {
            int &sc = level == 'A' ? (it->second).a : (level == 'B' ? (it->second).b : (it->second).t);
            sc += score;
            map<string, int>::iterator stuit = students.find(stuid);
            if (stuit == students.end())
                (it->second).ns += (students[stuid] = 1);
        }
    }
    for (map<string, record>::iterator it = list.begin(); it != list.end(); ++it) {
        record r = it->second;
        r.tws = r.b / 1.5 + r.a + r.t * 1.5;
        r.school = it->first;
        ans.push_back(r);
    }
    sort(ans.begin(), ans.end(), cmp);
    int i, j, k = -1, len = ans.size();
    cout << len << endl;
    for (i = 0; i < len; ++i) {
        if (ans[i].tws != k) {
            j = i + 1;
            k = ans[i].tws;
        }
        printf("%d %s %d %d\n", j, ans[i].school.c_str(), ans[i].tws, ans[i].ns);
    }
    return 0;
}
*/
