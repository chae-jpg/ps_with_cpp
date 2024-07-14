#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef pair<int, pi> pii;

vector<int> link, len;

int find(int n) {
    while (link[n] != n) n = link[n];
    return n;
}

void unite(int a, int b) {
    a = find(a); b = find(b);
    if (len[a]<len[b]) swap(a, b);
    link[b] = a;
    len[a] += len[b];
}

int main() {
    int n; cin >> n;
    long long cost = 0;
    link.assign(n, 0); len.assign(n, 1);
    for (int i = 0; i < n; i++) link[i] = i;

    vector<vector<int>> dist(n, vector<int> (n, 0));
    priority_queue<pii> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
            if (dist[i][j]) {
                pq.push({-dist[i][j], {i, j}});
            }
        }
    }

    while (!pq.empty()) {
        pii top = pq.top();
        pq.pop();
        int d = -top.first;
        int a = top.second.first, b = top.second.second;
        if (find(a) == find(b)) continue;
        unite(a, b);
        cost += d;
    }
    cout << cost;
}