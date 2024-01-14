//노드사이의 거리 - 골드 5

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m;
vector<vector<pi>> graph;
vector<bool> visited;

int solve(int a, int b) {
    visited.assign(n+1, false);
    queue<pi> q;

    //노드, 거리
    q.push({a, 0});

    while (!q.empty()) {
        pi top = q.front();
        int v = top.first, w = top.second;
        q.pop();
        if (visited[v]) continue;
        visited[v] = true;
        if (v == b) return w;


        for (pi p : graph[v]) {
            q.push({p.first, w + p.second});
        }
    }
}

int main() {
    cin >> n >> m;
    graph.assign(n+1, vector<pi> ());

    for (int i = 0; i < n-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        cout << solve(a, b) << '\n';
    }



}