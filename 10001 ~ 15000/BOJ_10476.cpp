//좁은 미술전시관 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int n, k;

vector<vector<int>> board;
vector<vector<vector<int>>> dp;

int main() {
    cin >> n >> k;
    board.assign(n+1, vector<int> (2, 0));
    dp.assign(n+2, vector<vector<int>> (k+2, vector<int> (3, 0)));

    for (int i = 1; i <= n; i++) {
        cin >> board[i][0] >> board[i][1];
    }
    //0 : 왼쪽 닫, 1 : 오른쪽 닫, 2 : 다 열림
    dp[1][1][0] = board[1][1];
    dp[1][1][1] = board[1][0];
    dp[1][0][2] = board[1][0] + board[1][1];

    for (int j = 0; j <= k; j++) {
        for (int i = 2; i <= n; i++) {
            //닫은 문의 개수가 라인보다 클 때 -> skip
            if (j > i) continue;
            if (j) {
                dp[i][j][0] = max(dp[i-1][j-1][0], dp[i-1][j-1][2]) + board[i][1];
                dp[i][j][1] = max(dp[i-1][j-1][1], dp[i-1][j-1][2]) + board[i][0];
            }
            if (i != j)
                dp[i][j][2] = max({dp[i-1][j][0], dp[i-1][j][1], dp[i-1][j][2]}) + board[i][0] + board[i][1];
        }
    }

    cout << max({dp[n][k][0], dp[n][k][1], dp[n][k][2]});
}