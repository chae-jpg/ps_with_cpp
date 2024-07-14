//웜홀 - 골드 3

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
typedef pair<int, int> pi;

vector<vector<int>> graph;
vector<int> dist;
int n, m, w;

bool solve() {
    for (int h = 1; h <= n; h++) {
        dist.assign(n+1, INF);
        dist[h] = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (graph[j][k] == INF) continue;
                    dist[k] = min(dist[k], dist[j] + graph[j][k]);
                }
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (graph[j][k] == INF) continue;
                if (dist[k] > dist[j] + graph[j][k]) return false;
            }
        }

    }
    return true;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        cin >> n >> m >> w;
        graph.assign(n+1, vector<int> (n+1, INF));
        dist.assign(n+1, INF);

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a][b] = min(graph[a][b], c);
            graph[b][a] = min(graph[b][a], c);
        }
        for (int i = 0; i < w; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a][b] = min(graph[a][b], -c);
        }
        if (solve()) cout << "NO\n";
        else cout << "YES\n";
    }


}