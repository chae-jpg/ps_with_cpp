#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> link;
vector<bool> visited;
int cnt;

void dfs(int node) {
    visited[node] = true;
    cnt++;
    if (!visited[link[node]]) dfs(link[node]);
}

int main() {
    int max_cnt = 0, idx = 0;
    cin >> n;
    link.assign(n+1, 0);

    for (int i = 1; i <= n; i++) cin >> link[i];

    for (int i = n; i >= 1; i--) {
       cnt = 0;
       visited.assign(n+1, false);
        dfs(i);
       if (max_cnt <= cnt) {
           max_cnt = cnt;
           idx = i;
       }
    }

    cout << idx;

}