// 팰린드롬? - 골드 4

#include <bits/stdc++.h>

using namespace std;

int n, m, s, e;
vector<vector<bool>> dp;
vector<int> v;

void setDp() {
    for (int i = 1; i <= n; i++) {
        dp[i][1] = true;
    }

    // 차이
    for (int i = 1; i <= n; i++) {
        // 시작 인덱스
        for (int j = 0; i + j < n; j++) {
            if (v[j] == v[j+i] && dp[j+1][j+i-1]) dp[j][j+i] = true;
            else dp[j][j+i] = false;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    v.assign(n, 0);
    dp.assign(n+1, vector<bool> (n+1, true));

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    setDp();
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> s >> e;
        cout << dp[s-1][e-1] << '\n';
    }

}