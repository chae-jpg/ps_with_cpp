//플로이드 - 골드 4
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, a, b, c;
    vector<vector<int>> dist, adj;

    cin >> n >> m;
    dist.assign(n+1, vector<int> (n+1, 0));
    adj.assign(n+1, vector<int> (n+1, INF));

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a][b] = min(c, adj[a][b]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
                continue;
            }
            if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j]= INF;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) cout << 0;
            else cout << dist[i][j];
            cout << ' ';
        }
        cout << '\n';
    }
}
