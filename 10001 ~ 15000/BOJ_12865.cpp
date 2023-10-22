//평범한 배낭 - 골드 5

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

int set_dp(vector<pi>& stuff, vector<vector<int>>& dp, int n, int k) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < stuff[i].first) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-stuff[i].first] + stuff[i].second);
        }
    }
    return dp[n][k];
}

int main() {
    int n, k;
    vector<pi> stuff;
    vector<vector<int>> dp;
    cin >> n >> k;
    stuff.assign(n + 1, {0, 0});
    dp.assign(n+1, vector<int> (k + 1, 0));

    for (int i = 1; i <= n; i++) {
        cin >> stuff[i].first >> stuff[i].second;
    }

    cout << set_dp(stuff, dp, n, k);
}