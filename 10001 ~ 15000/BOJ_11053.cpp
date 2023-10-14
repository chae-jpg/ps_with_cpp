#include <iostream>
#include <vector>

using namespace std;

int getLcs (const vector<int>& arr, vector<int>& dp) {
    int answer = 0;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 1; j <= i+1; j++) {
            if (dp[j] < arr[i]) continue;
            dp[j] = min(arr[i], dp[j]);
            answer = max(j, answer);
            break;
        }
    }

    return answer;
}

int main() {
    int n;
    vector<int> arr, dp;
    cin >> n;
    arr.assign(n, 0);
    dp.assign(n + 1, 1234567);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << getLcs(arr,dp);

}