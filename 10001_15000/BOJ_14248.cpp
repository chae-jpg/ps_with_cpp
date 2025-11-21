// 점프 점프 - 실버 2

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n; cin >> n;
    vector<int> v(n+1, 0);
    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int s; cin >> s;
    queue<int> q;

    q.push(s);

    while(!q.empty()) {
        int top = q.front();
        q.pop();
        visited[top] = true;

        if(top - v[top] >= 1 && !visited[top - v[top]]) q.push(top - v[top]);
        if (top + v[top] <=n && !visited[top + v[top]]) q.push(top + v[top]);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) cnt++;
    }

    cout << cnt;
}