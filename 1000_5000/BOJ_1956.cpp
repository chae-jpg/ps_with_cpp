//운동 - 골드 4

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
const int INF = 1e9+7;

using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<pi>> graph (v+1, vector<pi>());
    vector<vector<int>> dist(v+1, vector<int> (v+1, INF));
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        dist[a][b] = c;
    }

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (int k = 1; k <= v; k++) {
                if (dist[j][k] > dist[j][i] + dist[i][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
            }
        }
    }

    int min_len = INF;

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            min_len = min(min_len, dist[i][j] + dist[j][i]);
        }
    }
    if (min_len == INF) cout << -1;
    else cout << min_len;
}