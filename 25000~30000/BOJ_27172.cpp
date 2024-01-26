//수 나누기 게임 - 골드 5

#include <bits/stdc++.h>

using namespace std;

vector<int> v, ans;
vector<int> is_prime;
unordered_map<int, int> m;

void findPrime() {
    is_prime.assign(1e6+1, 0);
    is_prime[1] = false;
    for (int i = 2; i * i <= 1e6; i++) {
        if (is_prime[i]) continue;
        for (int j = i*i; j <= 1e6; j += i) {
            if (!is_prime[j]) {
                is_prime[j] = i;
            }
        }
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    v.assign(n, 0);
    ans.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]] = i;
    }
    sort(v.begin(), v.end());
    findPrime();

    for (int i = 0; i < n; i++) {
        if (!is_prime[v[i]]) {
            for (int j = 0; j <= i-1; j++) {
                if (v[j] % v[i] == 0) {
                    ans[m[v[j]]]--;
                    ans[m[v[i]]]++;
                }
            }
        }
        for (int j = i+1; j < n; j++) {
            if (is_prime[v[j]]) continue;
            if (v[j] % v[i] == 0) {
                ans[m[v[j]]]--;
                ans[m[v[i]]]++;
            }
        }
    }

    for (auto i : ans) {
        cout << i << ' ';
    }

}