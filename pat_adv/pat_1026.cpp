#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

struct record {
	int arrive, apart, last, isvip, wait;
	friend bool operator <(record r1, record r2) {
		r1.arrive < r2.arrive;
	}
};

struct table {
	int count, left, isvip, num;
	friend bool operator <(table t1, table t2) {
		return t1.left < t2.left;
	}
};

vector <record> R;
vector <record *> V;
table T[128];
priority_queue <table> Q;

int main()
{
	int n, i, j, k, h, m, s, time, K, M, head;
	record temp;
	table temp1;
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d:%d:%d %d %d", &h, &m, &s, &temp.last, &temp.isvip);
		temp.arrive = 3600 * h + 60 * m + s;
		temp.wait = 0;
		R.push_back(temp);
	}
	sort(R.begin(), R.end());
	for (i = 0; i < n; i++)
		if (R[i].isvip)
			V.push_back(&(R[i]));
	scanf("%d %d", &K, &M);
	for (i = 0; i < M; i++) {
		scanf("%d", &j);
		T[j].isvip = 1;
	}
	for (i = 1; i <= K; i++)
		Q.push(T[i]);
	head = 0;
	for (i = 1; i <= k; i++) {
	while (head < n) {
		
	return 0;
}