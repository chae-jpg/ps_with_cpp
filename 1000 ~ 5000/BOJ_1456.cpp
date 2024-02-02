//거의 소수 - 골드 5

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e7;

vector<bool> is_prime(INF+1, true);
vector<long long> prime;

void findPrime() {
    for (long long i = 2; i <= INF; i++) {
        if (!is_prime[i]) continue;
        prime.push_back(i);
        for (long long j = 2*i; j <= INF; j+=i) {
            is_prime[j] = false;
        }

    }


}

int main() {
    int cnt = 0;
    long long a, b; cin >> a >> b;
    findPrime();

    for (int i = 0; i < prime.size(); i++) {
        long long t = prime[i] * prime[i];
        while (t <= b) {
            if (t >= a) cnt++;
            if (t >= 1e14 / prime[i]) break;
            t *= prime[i];

        }
    }
    cout << cnt;
}