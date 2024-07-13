//택배 배송 - 골드 5

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

typedef pair<int, int> pi;

int main() {
    int n, m;
    vector<vector<pi>> graph;
    vector<int> dist;
    vector<bool> visited;
    priority_queue<pi> q;
    cin >> n >> m;
    graph.assign(n + 1, vector<pi> ());
    dist.assign(n+1, INF);
    visited.assign(n+1, false);

    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dist[1] = 0;
    q.push({0, 1});

    while(!q.empty()){
        pi top = q.top();
        q.pop();
        int a = top.second;

        for (auto u : graph[a]) {
           int b = u.first, w = u.second;
           if (dist[a] + w < dist[b]) {
               dist[b] = dist[a]+w;
               q.push({-dist[b], b});
           }
        }
    }

    cout << dist[n];
}