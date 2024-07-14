//연속합 - 실버 2

#include <iostream>
#include <vector>

using namespace std;

int calcMax(const vector<int>& arr, vector<int>& dp) {
    //여기 -1001로 초기화시켰다가 dp[1]이랑 max 비교하는 부분 없어서 틀림;
    int max_sum = arr[0];

    dp[0] = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        dp[i] = (arr[i] > dp[i-1] + arr[i]) ? arr[i] : dp[i-1] + arr[i];
        max_sum = max(dp[i], max_sum);
    }

    return max_sum;
}

int main() {
    int n;
    vector<int> arr;
    vector<int> dp;

    cin >> n;
    arr.assign(n, 0);
    dp.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << calcMax(arr, dp);

}