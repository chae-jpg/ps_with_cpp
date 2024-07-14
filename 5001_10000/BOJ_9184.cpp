//신나는 함수 실행 - 실버 2

#include <iostream>

using namespace std;

int dp[21][21][21] = {0};

int w(int a, int b, int c) {
    if (a<=0 || b<=0 || c<=0) return 1;
    if (a> 20 ||b > 20 || c> 20) {
        if (!dp[20][20][20]) dp[20][20][20] = w(20, 20, 20);
        return dp[20][20][20];
    }
    if (a <b && b < c) {
        if (!dp[a][b][c-1]) dp[a][b][c-1]= w(a, b, c-1);
        if (!dp[a][b-1][c-1]) dp[a][b-1][c-1]= w(a, b-1, c-1);
        if (!dp[a][b-1][c]) dp[a][b-1][c]= w(a, b-1, c);
        return dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c];
    }
    if (!dp[a-1][b][c]) dp[a-1][b][c]= w(a-1, b, c);
    if (!dp[a-1][b-1][c]) dp[a-1][b-1][c]= w(a-1, b-1, c);
    if (!dp[a-1][b][c-1]) dp[a-1][b][c-1]= w(a-1, b, c-1);
    if (!dp[a-1][b-1][c-1]) dp[a-1][b-1][c-1]= w(a-1, b-1, c-1);
    return dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] - dp[a-1][b-1][c-1];
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c;

    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) <<'\n';
    }


}