#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char level;
    int site, date, num, score;
} record;

typedef struct {
    int count, score;
} site_rec;

typedef struct {
    short site, count;
    int date;
} date_rec;

int cmp1(const void *a, const void *b) {
    record *pa = (record *)a, *pb = (record *)b;
    if (pa->level != pb->level)
        return pa->level - pb->level;
    if (pa->score != pb->score)
        return pb->score - pa->score;
    if (pa->site != pb->site)
        return pa->site - pb->site;
    if (pa->date != pb->date)
        return pa->date - pb->date;
    return pa->num - pb->num;
}

int cmp3(const void *a, const void *b) {
    record *pa = *(record **)a, *pb = *(record **)b;
    if (pa->date != pb->date)
        return pa->date - pb->date;
    return pa->site - pb->site;
}

int cmp(const void *a, const void *b) {
    date_rec *pa = (date_rec *)a, *pb = (date_rec *)b;
    if (!pa->count)
        return 1;
    if (pa->date != pb->date)
        return pa->date - pb->date;
    if (pb->count != pa->count)
        return pb->count - pa->count;
    return pa->site - pb->site;
}

int main() {
    int n, m, i, j, k, pb = 0, pt = 0, qi, type, datep[1000000][2] = {0}, date, site;
    record a[10000], *t3[10000];
    site_rec sites[1000] = {0};
    date_rec dates[10000] = {0};
    freopen("input", "r", stdin);
    scanf("%d %d\n", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%c%3d%6d%3d%d\n", &a[i].level, &a[i].site, &a[i].date, &a[i].num, &a[i].score);
        pt += a[i].level != 'T';
        pb += a[i].level == 'A';
        t3[i] = &a[i];
        sites[a[i].site].score += a[i].score;
        ++sites[a[i].site].count;
    }
    qsort(a, n, sizeof(record), cmp1);
    qsort(t3, n, sizeof(t3[0]), cmp3);
    dates[k = 0].date = date = t3[0]->date;
    dates[k].site = site = t3[0]->site;
    ++dates[k].count;
    datep[date][0] = k;
    for (i = 1; i < n; ++i) {
        if (t3[i]->date != date) {
            datep[date][1] = k;
            dates[++k].date = date = t3[i]->date;
            dates[k].site = site = t3[i]->site;
            datep[date][0] = k;
        }
        else if (t3[i]->site != site) {
            dates[++k].site = site = t3[i]->site;
            dates[k].date = date;
        }
        ++dates[k].count;
    }
    datep[date][1] = k;
    qsort(dates, k + 1, sizeof(date_rec), cmp);
    for (qi = 1; qi <= m; ++qi) {
        scanf("%d ", &type);
        if (type == 1) {
            char l;
            scanf("%c", &l);
            printf("Case %d: %d %c\n", qi, type, l);
            if ((l == 'A' && !pb) || (l == 'B' && pt == pb) || (l == 'T' && pt == n))
                printf("NA\n");
            else {
                int begin = l == 'A' ? 0 : (l == 'B' ? pb : pt);
                int end = l == 'A' ? pb : (l == 'B' ? pt : n);
                for (i = begin; i < end; ++i)
                    printf("%c%03d%06d%03d %d\n", a[i].level, a[i].site, a[i].date, a[i].num, a[i].score);
            }
        }
        else if (type == 2) {
            scanf("%d", &site);
            printf("Case %d: %d %d\n", qi, type, site);
            if (!sites[site].count)
                printf("NA\n");
            else
                printf("%d %d\n", sites[site].count, sites[site].score);
        }
        else {
            scanf("%d", &date);
            printf("Case %d: %d %06d\n", qi, type, date);
            if (dates[datep[date][0]].date != date)
                printf("NA\n");
            else
                for (i = datep[date][0]; i <= datep[date][1]; ++i)
                    printf("%d %d\n", dates[i].site, dates[i].count);
        }
    }
    return 0;
}

/** code below also works, but almost touch the time limit **/
/*
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct {
    string card;
    int score;
} record;

typedef struct {
    int count, score;
} site_rec;

typedef struct {
    int site, count;
} date_rec;

bool cmp(const record &a, const record &b) {
    if (a.card[0] == b.card[0]) {
        if (a.score == b.score)
            return a.card < b.card;
        return a.score > b.score;
    }
    return a.card[0] < b.card[0];
}

bool cmp1(const date_rec &a, const date_rec &b) {
    if (a.count == b.count)
        return a.site < b.site;
    return a.count > b.count;
}

int main() {
    int n, m, site, pa = 0, pb = 0, pt = 0, qi, type;
    vector<record> cards;
    record a[10000];
    site_rec sites[1000] = {0};
    map<string, map<int, int>> dates;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        record rcd;
        cin >> rcd.card >> rcd.score;
        site = (rcd.card[1] - '0') * 100 + (rcd.card[2] - '0') * 10 + (rcd.card[3] - '0');
        ++sites[site].count;
        sites[site].score += rcd.score;
        pt += rcd.card[0] != 'T';
        pb += rcd.card[0] == 'A';
        cards.push_back(rcd);
        string date = rcd.card.substr(4, 6);
        map<string, map<int, int>>::iterator dit = dates.find(date);
        if (dit == dates.end())
            dates[date][site] = 1;
        else {
            map<int, int>::iterator sit = dit->second.find(site);
            if (sit == dit->second.end())
                dit->second[site] = 1;
            else
                ++sit->second;
        }
    }
    sort(cards.begin(), cards.end(), cmp);
    for (qi = 1; qi <= m; ++qi) {
        cin >> type;
        printf("Case %d: %d ", qi, type);
        if (type == 1) {
            char level;
            cin >> level;
            cout << level << endl;
            if ((level == 'A' && !pb) || (level == 'B' && (pb == pt)) || (level == 'T' && pt == n))
                cout << "NA" << endl;
            else {
                int begin = level == 'A' ? 0 : (level == 'B' ? pb : pt);
                int end = level == 'A' ? pb : (level == 'B' ? pt : n);
                for (int i = begin; i < end; ++i)
                    cout << cards[i].card << ' ' << cards[i].score << endl;
            }
        }
        else if (type == 2) {
            cin >> site;
            cout << site << endl;
            if (!sites[site].count)
                cout << "NA" << endl;
            else
                cout << sites[site].count << ' ' << sites[site].score << endl;
        }
        else {
            string date;
            cin >> date;
            cout << date << endl;
            map<string, map<int, int>>::iterator dit = dates.find(date);
            if (dit == dates.end())
                cout << "NA" << endl;
            else {
                vector<date_rec> dr;
                for (map<int, int>::iterator it = dit->second.begin(); it != dit->second.end(); ++it) {
                    date_rec temp;
                    temp.site = it->first;
                    temp.count = it->second;
                    dr.push_back(temp);
                }
                sort(dr.begin(), dr.end(), cmp1);
                for (vector<date_rec>::iterator it = dr.begin(); it != dr.end(); ++it)
                    cout << it->site << ' ' << it->count << endl;
            }
        }
    }
    return 0;
}
*/
