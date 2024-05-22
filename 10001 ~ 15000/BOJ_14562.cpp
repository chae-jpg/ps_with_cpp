// 태권왕 - 실버 1

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int s, t;

int solve() {
    queue<pi> q;

    q.push({s, t});
    int cnt = 0;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            pi top = q.front();
            q.pop();
            if (top.first == top.second) return cnt;
            if (top.first *2 <= top.second + 3) {
                q.push({top.first*2, top.second+3});
            }
            q.push({top.first+1, top.second});
        }
        cnt++;
    }



}

int main() {
    int c; cin >> c;
    while (c--) {
        cin >> s >> t;
        cout << solve() << '\n';
    }



}