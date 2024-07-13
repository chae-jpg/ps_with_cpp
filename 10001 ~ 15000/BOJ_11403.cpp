//경로 찾기 - 실버 1

#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> graph;
vector<bool> visited;
vector<vector<int>> answer;

int n;

void dfs(int cur, int next) {
    visited[next] = true;
    for (int i =1; i <= n; i++) {
        if (graph[next][i]) {
            answer[cur][i] = 1;
            if (!visited[i]) dfs(cur, i);
        }
    }
}

int main() {

    cin >> n;
    graph.assign(n+1, vector<bool> (n+1, false));
    answer.assign(n+1, vector<int> (n+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= n; j++) {
            int t; cin >> t;
            graph[i][j] = t;
        }
    }

    for (int i = 1; i <= n; i++) {
        visited.assign(n+1, false);
        dfs(i, i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= n; j++) {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
}