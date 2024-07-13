//Dance Dance Revolution - 골드 3

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+7;
vector<vector<vector<int>>> dp;
int seq[100000];

int calcPow(int cur, int next) {
    if (cur == next) return 1;
    if (cur == 0) return 2;
    if (cur == 1) {
        if (next == 2) return 3;
        if (next == 3) return 4;
        if (next == 4) return 3;
    }
    if (cur == 2) {
        if (next == 1) return 3;
        if (next == 3) return 3;
        if (next == 4) return 4;
    }
    if (cur == 3) {
        if (next == 1) return 4;
        if (next == 2) return 3;
        if (next == 4) return 3;
    }
    if (cur == 4) {
        if (next == 1) return 3;
        if (next == 2) return 4;
        if (next == 3) return 3;
    }
}

int main() {
    int t, idx = 0;
    while (cin >> t && t) {
        seq[idx++] = t;
    }

    dp.assign(idx+1, vector<vector<int>> (5, vector<int> (5, INF)));

    dp[0][0][0] = 0;

    for (int i = 0; i < idx; i++) {
        int next = seq[i];
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (dp[i][j][k] == INF) continue;
                int l = j, r = k;
                int l_move = calcPow(l, next), r_move = calcPow(r, next);
                dp[i+1][l][next] = min(dp[i+1][l][next], dp[i][l][r] + r_move);
                dp[i+1][next][r] = min(dp[i+1][next][r], dp[i][l][r] + l_move);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ans = min(ans, dp[idx][i][j]);
        }
    }
    cout << ans;
}