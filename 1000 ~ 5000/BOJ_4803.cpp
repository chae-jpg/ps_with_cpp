#include <iostream>
#include <vector>
using namespace std;

void printResult(int tc, int cnt) {
    cout << "Case " << tc << ": ";

    switch(cnt) {
        case 0 :
            cout << "No trees.\n";
            break;
        case 1 :
            cout << "There is one tree.\n";
            break;
        default :
            cout << "A forest of " << cnt << " trees.\n";
    }
    return;
}

void dfs(bool& flag, int cur, int prev, vector<vector<int>>& graph, vector<bool>& visited) {

    //dfs 도는 중에 방문한 곳을 또 방문 -> cycle
    if (visited[cur]) {
        flag = false;
        return;
    }

    visited[cur] = true;

    for (int next : graph[cur]) {
        if (next == prev) {
            continue;
        }
        dfs(flag, next, cur, graph, visited);
    }
    return;
}

int main() {
    int n, m, v1, v2, t = 0;
    while (cin >> n >> m && n) {
        t++;
        vector<vector<int>> graph (n+1, vector<int> (0));
        while (m--) {
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        int cnt = 0;
        vector<bool> visited(n+1, false);

        for (int i = 1; i <= n; i++) {
            if (visited[i]) {
                continue;
            }

            bool flag = true;
            dfs(flag, i, 0, graph, visited);
            if (flag) {
                cnt++;
            }
        }
        printResult(t, cnt);
    }
}