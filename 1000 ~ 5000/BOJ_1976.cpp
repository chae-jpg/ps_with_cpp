//여행 가자 - 골드 4

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> link, len, plan;

int find(int x) {
    while (link[x] != x) x = link[x];
    return x;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;

    if (len[a] < len[b]) swap(a, b);
    link[b] = a;
    len[a] += len[b];
}

bool solve() {
    for (int i = 1; i <= n; i++) link[i] = i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (graph[i][j]) unite(i, j);
        }
    }

    int parent = find(plan[0]);

    for (int i = 1; i < m; i++) {
        if (find(plan[i]) != parent) return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    graph.assign(n+1, vector<int> (n+1, 0));
    link.assign(n+1, 0);
    len.assign(n+1, 1);
    plan.assign(m, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> plan[i];
    }

    if (solve()) cout << "YES";
    else cout << "NO";

}