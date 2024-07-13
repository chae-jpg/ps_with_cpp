//루머 - 골드 4

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m;
vector<vector<int>> rel;
vector<bool> rumor;
vector<int> ans;
queue<pi> q;

void solve() {
    int time = 0;
    for (int i = 1; i <= n; i++) {
        if (rumor[i]) {
            q.push({i, 0});
            ans[i] = 0;
        }
    }

    while (!q.empty()) {
        int spoiler = q.front().first;
        time = q.front().second;
        q.pop();

        for (int target : rel[spoiler]) {
            if (rumor[target]) continue;
            int ppl_cnt = rel[target].size(), r_cnt = 0;
            for (int t_rel : rel[target]) {
                if (time+1 != ans[t_rel] && rumor[t_rel]) r_cnt++;
            }
            if (r_cnt >= (ppl_cnt+1)/2) {
                q.push({target, time + 1});
                ans[target] = time+1;
                rumor[target] = true;
            }
        }



    }

}

int main() {
    cin >> n;
    rel.assign(n+1, vector<int>());
    rumor.assign(n+1, false);
    ans.assign(n+1, -1);
    for (int i = 1; i <= n; i++) {
        int t;
        while (cin >> t && t){
            rel[i].push_back(t);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        rumor[t] = true;
    }

    solve();

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}