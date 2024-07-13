#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1234567;
vector<vector<long long>> dp(1001, vector<long long>(10, -1));

long long recur(int num, int cnt) {
    if (cnt == 0) return 0;
    if (dp[cnt][num] != -1) return dp[cnt][num];

    switch(num) {
        case 1:
            return dp[cnt][1] = (recur(4, cnt-1) + recur(2, cnt-1)) % MOD;
        case 2 :
            return dp[cnt][2] = (recur(1, cnt-1) + recur(3, cnt-1) + recur(5, cnt-1)) % MOD;
        case 3 :
            return dp[cnt][3] = (recur(2, cnt-1) + recur(6, cnt-1)) % MOD;
        case 4 :
            return dp[cnt][4] = (recur(1, cnt-1) + recur(5, cnt-1) + recur(7, cnt-1)) % MOD;
        case 5 :
            return dp[cnt][5] = (recur(2, cnt-1) + recur(4, cnt-1) + recur(6, cnt-1) + recur(8, cnt-1)) % MOD;
        case 6 :
            return dp[cnt][6] = (recur(3, cnt-1) + recur(5, cnt-1) + recur(9, cnt-1)) % MOD;
        case 7 :
            return dp[cnt][7] = (recur(4, cnt-1) + recur(8, cnt-1) + recur(0, cnt-1)) % MOD;
        case 8 :
            return dp[cnt][8] = (recur(5, cnt-1) + recur(7, cnt-1) + recur(9, cnt-1)) % MOD;
        case 9 :
            return dp[cnt][9] = (recur(6, cnt-1) + recur(8,cnt-1)) % MOD;
        case 0 :
            return dp[cnt][0] = (recur(7, cnt-1)) % MOD;
    }
    return 0;
}

void solve() {
    for (int i = 0; i < 10; i++) {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }

    for (int i = 0; i < 10; i++) {
        recur(i, 1000);
    }
}

int main() {
    int t; cin >> t;

    solve();

    while (t--) {
        int a; cin >> a;
        long long ans = 0;

        for (int i = 0; i < 10; i++) {
            ans = (ans + dp[a][i]) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
