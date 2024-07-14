//합분해 - 골드 5

#include <iostream>
#include <vector>
using namespace std;


int dp(int n, int k) {
    vector<vector<int>> arr(k+1, vector<int> (n+1, 0));

    for (int i = 1; i <= k; i++) {
        arr[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            arr[i][j] = (arr[i][j-1] + arr[i-1][j]) % 1000000000;
        }
    }
    return arr[k][n];
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << dp(n, k);
}