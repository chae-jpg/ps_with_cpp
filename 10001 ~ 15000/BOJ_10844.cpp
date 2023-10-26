//쉬운 계단 수 - 실버 1

#include <iostream>
#include <vector>

using namespace std;

const int DIV = 1e9;

void setDp(int dp[100][10], int n) {
    dp[0][0] = 0;
    for (int i = 1; i <= 9; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = (dp[i-1][1]) % DIV;
        dp[i][9] = (dp[i-1][8]) % DIV;

        for (int j = 1; j <= 8; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % DIV;
        }
    }
}

int main() {
    int n;

    cin >> n;
    int dp[100][10], sum = 0;
    setDp(dp, n);

    for (int i = 0; i < 10; i++) {
        sum = (sum + dp[n-1][i]) % DIV;
    }
    cout << sum;
}