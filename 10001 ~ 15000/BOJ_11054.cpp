//가장 긴 바이토닉 부분 수열 - 골드 4

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp;

void setDp(int n, const vector<int>& arr) {
    for (int i = 1; i < n; i++) {
        int l = arr[i], r = arr[n - i - 1];
        for (int j = 0; j < i; j++) {
            if (arr[j] < l) dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            if (arr[n - j - 1] < r) dp[n - i -1][1] = max(dp[n-i-1][1], dp[n - j -1][1] + 1);
        }
    }
}

int main() {
    int n, answer = -1;
    vector<int> arr;
    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, vector<int> (2, 1));

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    setDp(n, arr);

    for (int i = 0; i < n; i++) {
        answer = max(answer, dp[i][0] + dp[i][1]);
    }
    cout << answer-1;
}