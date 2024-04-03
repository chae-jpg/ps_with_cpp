// 텀 프로젝트 - 골드 3

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> team;
vector<int> visited;

int cnt = 0;
void dfs(int cur) {
    //방문만 한 상태로 설정, 판단 완료 : 2
    visited[cur] = 1;

    if (!visited[team[cur]]) dfs(team[cur]);
    // 방문은 했는데 아직 배정은 안 됨 -> 사이클
    else if (visited[team[cur]] == 1) {
        int t = team[cur];
        while (t != cur) {
            t = team[t];
            cnt++;
        }
        cnt++;
    }
    //판단 끝
    visited[cur] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        cnt = 0;
        cin >> n;
        team.assign(n+1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> team[i];
        }
        visited.assign(n+1, false);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (visited[i]) continue;
            dfs(i);
        }
        cout << n-cnt << '\n';
    }






}