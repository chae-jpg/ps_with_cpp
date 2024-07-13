//계단 오르기 - 실버 3

#include <iostream>
#include <vector>

using namespace std;

void setDp(const vector<int>& arr, vector<vector<int>>& dp, int n) {
    dp[0][0] = arr[0];
    if (n == 1) return;

    dp[1][0] = arr[0] + arr[1];
    dp[1][1] = arr[1];
    if (n == 2) return;

    for (int i = 2; i < n; i++) {
        dp[i][0] = dp[i-1][1] + arr[i];
        dp[i][1] = max(dp[i-2][0], dp[i-2][1]) + arr[i];
    }
}

int main() {
    int n;
    vector<int> arr;
    vector<vector<int>> dp;
    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, vector<int> (2, 0));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    setDp(arr, dp, n);
    cout << max(dp[n-1][0], dp[n-1][1]);

}