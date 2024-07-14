// 동물원 - 실버 1

#include <bits/stdc++.h>

using namespace std;

const int LIM = 9901;

int main() {
    int n;
    cin >> n;
    // 둘다 x : 0, 왼쪽 : 1, 오른쪽 : 2
    vector<vector<int>> dp(n, vector<int>(3, 0));

    dp[0][0] = 1, dp[0][1] = 1, dp[0][2] = 1;

    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%LIM;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%LIM;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%LIM;
    }
    cout << (dp[n-1][0] + dp[n-1][1] + dp[n-1][2])%LIM;

}