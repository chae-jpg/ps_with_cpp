//수들의 합 5 - 실버 5

#include <bits/stdc++.h>

using namespace std;

int n;
int main() {
    int cnt = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        sum = 0;
        for (int j = i; j <= n; j++) {
            sum += j;
            if (sum < n) continue;
            if (sum == n) cnt++;
            break;
        }
    }
    cout << cnt;
}
