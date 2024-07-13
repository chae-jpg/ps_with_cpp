#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
const int INF = 987654321;

vector<vector<int>> graph;
vector<int> dist;
vector<bool> visited;

int n, m;
int start, arrive;

void solve() {
    priority_queue <pi> pq;

    dist[start] = 0;
    //가중치, 간선
    pq.push({dist[start], start});

    while (!pq.empty()) {
        pi top = pq.top();
        pq.pop();
        int v = top.second;
        if (visited[v]) continue;
        visited[v] = true;

        for (int i = 1; i <= n; i++) {
            if (graph[v][i] == INF) continue;
            dist[i] = min(dist[i], graph[v][i] + dist[v]);
            pq.push({-dist[i], i});
        }
    }

}

int main() {
    cin >> n >> m;
    graph.assign(n+1, vector<int> (n+1, INF));
    dist.assign(n+1, INF);
    visited.assign(n+1, false);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
    }
    cin >> start >> arrive;

    solve();

    cout << dist[arrive];
}