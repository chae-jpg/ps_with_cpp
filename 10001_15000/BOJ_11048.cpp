// 이동하기 - 실버 2

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> candy;
vector<vector<int>> dp;

int main() {
    cin >> n >> m;
    dp.assign(n+1, vector<int> (m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= m; j++) {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] += max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    cout << dp[n][m];
}