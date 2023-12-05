//점프 - 실버 1

#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<long long>> board, cnt;

void solve() {
    cnt[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!cnt[i][j]) continue;
            if (i == n-1 && j == n-1) break;
            int step = board[i][j];
            if (step + j < n) cnt[i][step+j] += cnt[i][j];
            if (step + i < n) cnt[i + step][j] += cnt[i][j];
        }
    }

}

int main() {
    cin >> n;
    board.assign(n, vector<long long> (n, 0));
    cnt.assign(n, vector<long long> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    solve();
    cout << cnt[n-1][n-1];

}