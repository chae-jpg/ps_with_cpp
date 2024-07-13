//리그 오브 레전설 - 실버 2

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
int dp[10001];

int n, m;

void solve() {
    for (int i = 2; i <=n; i++) {
        if (i == m) continue;
        int a = dp[i-1] % MOD;
        int b = 0;
        if (i-m>=0) b = dp[i-m] % MOD;
        dp[i] = (a+b)%MOD;
    }

}

int main() {
    cin >> n >> m;

    memset(dp, -1, sizeof(dp));
    dp[0] = 0, dp[1] = 1, dp[m] = 2;

    solve();

    cout << dp[n];

}