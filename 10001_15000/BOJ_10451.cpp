//순열 사이클 - 실버 3

#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<bool> visited;

void dfs(int i) {
    visited[i] = true;
    if (visited[arr[i]]) return;
    return dfs(arr[i]);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, cnt = 0;
        cin >> n;
        arr.assign(n+1, 0);
        visited.assign(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            dfs(i);
            cnt++;
        }
        cout << cnt << '\n';
    }



}