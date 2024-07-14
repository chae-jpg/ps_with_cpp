//우유 도시 - 골드 4

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> board;
vector<vector<vector<int>>> dp;

void solve() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j][0] = max(dp[i-1][j][0], dp[i][j-1][0]);
            if (dp[i][j][0] == 0) {
                if (board[i][j] == 0) dp[i][j][0] = 1;
                continue;
            }
            for (int k = 0; k < 3; k++) {
                if (board[i][j] == k) {
                    dp[i][j][k] = max({dp[i - 1][j][k] ,dp[i][j-1][k] ,dp[i - 1][j][(k-1<0 ? 2 : k-1)]+1, dp[i][j - 1][(k-1<0 ? 2 : k-1)]+1});
                }
                else {
                    dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k]);
                }
            }

        }
    }

}

int main() {
    cin >> n;
    board.assign(n+1, vector<int> (n+1, 0));
    dp.assign(n+1, vector<vector<int>> (n+1, vector<int> (3, 0)));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    solve();

    cout << max({dp[n-1][n-1][0], dp[n-1][n-1][1], dp[n-1][n-1][2]});
}