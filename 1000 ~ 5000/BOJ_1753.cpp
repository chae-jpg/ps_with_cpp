//최단경로 - 골드 4

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

const int INF = 987654321;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v, e, k;
    cin >> v >> e >> k;
    vector<vector<pi>> graph (v+1, vector<pi> ());
    vector<int> dist(v+1, INF);

    for (int i = 0; i < e; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    priority_queue<pi> q;

    q.push({0, k});
    dist[k] = 0;

    while (!q.empty()) {
        int node = q.top().second;
        q.pop();

        for (pi cur : graph[node]) {
            int v = cur.first, w = cur.second;

            if (dist[v] > dist[node] + w) {
                dist[v] = dist[node] + w;
                q.push({-dist[v], v});
            }
        }

    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i]<< '\n';
    }

}