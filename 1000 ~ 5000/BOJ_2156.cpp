//포도주 시식 - 실버 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int setDp(const vector<int>& arr, vector<vector<int>>& dp, int n) {
    int max_sum = 0, max_sum_before = arr[0];

    dp[0][0] = arr[0];
    if (n == 1) return arr[0];
    dp[1][0] = arr[1];
    dp[1][1] = arr[1] + arr[0];
    if (n == 2) return dp[1][1];
    max_sum = dp[1][1];

    for (int i = 2; i < n; i++) {
        dp[i][1] = dp[i-1][0] + arr[i];
        dp[i][0] = arr[i] + max_sum_before;
        max_sum_before = max_sum;
        max_sum = max({max_sum, dp[i][1], dp[i][0]});
    }

    return max_sum;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<int> arr;
    vector<vector<int>> dp;

    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    cout << setDp(arr, dp, n);
}