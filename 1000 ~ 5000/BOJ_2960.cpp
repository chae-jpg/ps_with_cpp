//에라스토네스의 체 - 실버 4

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k, cnt = 0, i;
    vector<bool> is_prime;
    cin >> n >> k;
    is_prime.assign(n+1, true);

    for (i = 2; i*i <= n; i++) {
        if (!is_prime[i]) continue;
        cnt++;
        if (cnt == k) {
            cout << i;
            return 0;
        }
        for (int j = i*i; j <= n; j+=i) {
            if(!is_prime[j]) continue;
            is_prime[j] = false;
            cnt++;
            if (cnt == k) {
                cout << j;
                return 0;
            }
        }
    }

    for (; i <= n; i++) {
        if (is_prime[i]) cnt++;
        if (cnt == k) {
            cout << i;
            return 0;
        }
    }

}