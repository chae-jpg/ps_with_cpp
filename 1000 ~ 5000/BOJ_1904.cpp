//01타일 - 실버 3

#include <iostream>

using namespace std;

const int DIV = 15746, ARR_SIZE = 1e6;


int dp[ARR_SIZE + 1] = {0};

void setDp(int n) {
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % DIV;
    }
}

int main() {

    int n;
    cin >> n;

    setDp(n);
    cout << dp[n];


}