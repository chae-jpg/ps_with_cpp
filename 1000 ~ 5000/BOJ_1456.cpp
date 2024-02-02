#include <bits/stdc++.h>
#include <cmath>

using namespace std;

const int INF = 1e7;

vector<bool> is_prime (INF + 1, true);
vector<int> prime;

void findPrime() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= INF; i++) {
        if (!is_prime[i]) continue;
        is_prime[i] = true;
        prime.push_back(i);
        for (int j = i*i; j <= INF; j+=i) {
            is_prime[j] = false;
        }
    }


}

int main() {
    unsigned long long a, b;
    int cnt = 0;
    cin >> a >> b;
    findPrime();

    int n = 2;
    while (true) {
        unsigned long long new_a = pow(a-1, 1.0/n) + 1;
        unsigned long long new_b = pow(b, 1.0/n);

        if (new_a >= new_b) {
            if (new_a == 1) break;
            else cnt++;
        }
        n++;
        int idx_a = lower_bound(prime.begin(), prime.end(), new_a) - prime.begin();
        int idx_b = lower_bound(prime.begin(), prime.end(), new_b) - prime.begin();
        if (prime[idx_b] > new_b) idx_b--;
        cnt += (idx_b - idx_a) + 1;

    }
    cout << cnt;
}