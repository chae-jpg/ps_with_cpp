//스타트링크 - 실버 1

#include <bits/stdc++.h>

using namespace std;

int f, s, g, u, d;

vector<bool> visited;

int main() {
    cin >> f >> s >> g >> u >> d;

    visited.assign(f+1, false);

    queue<int> q;

    q.push(s);
    visited[s] = true;
    int cnt = 0;
    if (s == g) {
        cout << cnt;
        return 0;
    }
    while(!q.empty()) {
        int len = q.size();
        cnt++;
        for (int i = 0; i < len; i++) {
            int top = q.front();
            q.pop();
            if (top - d == g || top + u == g) {
                cout << cnt;
                return 0;
            }
            if (top-d >= 1 && !visited[top-d]) {
                q.push(top-d);
                visited[top-d] = true;
            }
            if (top + u <= f && !visited[top+u]) {
                q.push(top+u);
                visited[top+u] = true;
            }
        }
    }

    cout << "use the stairs";
}