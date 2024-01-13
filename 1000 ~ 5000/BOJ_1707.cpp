//이분 그래프 - 골드 4

#include <bits/stdc++.h>

using namespace std;

int k, v, e;

vector<vector<int>> graph;
vector<char> color;
vector<bool> visited;
char cur;
bool flag;

void solve(int n) {
    if (visited[n]) return;
    visited[n] = true;
    for (int v : graph[n]) {
        if (color[v] == ' ') {
            cur = (color[n] == 'R') ? 'B' : 'R';
            color[v] = cur;
            solve(v);
        } else {
            if (color[v] == color[n]) {
                flag = false;
                return;
            }
        }
    }
}

int main() {
    cin >> k;

    while (k--) {
        cin >> v >> e;
        graph.assign(v+1, vector<int>());
        color.assign(v+1, ' ');
        visited.assign(v+1, false);
        for (int i = 0; i < e; i++) {
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cur = 'R';
        flag = true;
        for (int i = 1; i <= v; i++) {
            if (visited[i]) continue;
            solve(i);
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}