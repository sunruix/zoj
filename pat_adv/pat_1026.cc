#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct player {
	int arv, start, last, vip, wait = 0, cut = 0;
	friend bool operator <(const player& r1, const player& r2) {
		return r1.arv < r2.arv;
	}
};

bool cmp(const player& p1, const player& p2) {
    return p1.start < p2.start;
}

struct table {
	int count = 0, open = 0, id, vip = 0, busy = 0;
    friend bool operator <(const table& t1, const table& t2) {
        if (t1.busy)
            return t1.open != t2.open ? t1.open > t2.open : t1.id > t2.id;
        return
            t1.id > t2.id;
    }
};

int main() {
	int n, h, m, s, time, K, M, cut = 0;
    const int EOD = 21 * 3600;
    table tables[128], t;
    priority_queue <table> open, vopen;
    priority_queue <table> busy;
    vector <player> pq;
	player r;
	freopen("input", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d:%d:%d %d %d", &h, &m, &s, &r.last, &r.vip);
		r.start = r.arv = 3600 * h + 60 * m + s;
        r.last = r.last <= 120 ? r.last : 120;
        r.last *= 60;
		pq.push_back(r);
	}
    sort(pq.begin(), pq.end());
	scanf("%d %d", &K, &M);
	for (int i = 0, j; i < M; i++) {
		scanf("%d", &j);
        tables[j].vip = 1;
	}
	for (int i = 1; i <= K; i++) {
        tables[i].id = i;
        tables[i].vip ? vopen.push(tables[i]) : open.push(tables[i]);
    }
    for (int i = 0; i < n && pq[i].start < EOD; ++i) {
        if (pq[i].cut)
            continue;
        while (!busy.empty() && busy.top().open <= pq[i].arv) {
            t = busy.top();
            busy.pop();
            t.busy = 0;
            t.vip ? vopen.push(t) : open.push(t);
        }
        int os = open.size(), vos = vopen.size();
        if (os || vos) {
            priority_queue <table>* q = &open;
            if (pq[i].vip && vos) 
                q = &vopen;
            else if (os && vos)
                q = (open.top().id < vopen.top().id) ? &open : &vopen;
            else
                q = open.size() ? &open : &vopen;
            t = q->top();
            q->pop();
            t.open = pq[i].arv + pq[i].last;
        }
        else if (busy.top().open >= EOD) {
            pq[i].start = busy.top().open;
            continue;
        }
        else {
            t = busy.top();
            busy.pop();
            if (!t.vip) {
                vector<table> vt;
                while (!busy.empty() && busy.top().open == t.open) {
                    if (busy.top().vip) {
                        vt.push_back(t);
                        t = busy.top();
                        busy.pop();
                        break;
                    }
                    else {
                        vt.push_back(busy.top());
                        busy.pop();
                    }
                }
                for (int k = 0; k < vt.size(); ++k)
                    busy.push(vt[k]);
            }
            int j = i;
            if (t.vip && !pq[i].vip) {
                for (j = i + 1; (pq[j].cut || (pq[j].arv <= t.open && !pq[j].vip)) && j < n; ++j);
                if (j < n && pq[j].vip && pq[j].arv <= t.open)
                    cut = pq[j].cut = 1;
                else {
                    j = i;
                    busy.push(t);
                    t = busy.top();
                    busy.pop();
                }
            }
            pq[j].start = t.open;
            if (t.open >= EOD)
                continue;
            pq[j].wait = pq[j].start - pq[j].arv;
            t.open += pq[j].last;
        }
        t.busy = 1;
        ++t.count;
        tables[t.id] = t;
        busy.push(t);
        if (cut) {
            --i;
            cut = 0;
        }
    }
    sort(pq.begin(), pq.end(), cmp);
    for (int i = 0; i < n; ++i) {
        if (pq[i].start < EOD) {
            h = pq[i].arv / 3600;
            m = (pq[i].arv - h * 3600) / 60;
            s = (pq[i].arv - h * 3600) % 60;
            printf("%02d:%02d:%02d ", h, m, s);
            h = pq[i].start / 3600;
            m = (pq[i].start - h * 3600) / 60;
            s = (pq[i].start - h * 3600) % 60;
            printf("%02d:%02d:%02d %d\n", h, m, s, (pq[i].wait + 30) / 60);
        }
    }
    for (int i = 1; i < K; ++i)
        printf("%d ", tables[i].count); 
    printf("%d\n", tables[K].count);
	return 0;
}

