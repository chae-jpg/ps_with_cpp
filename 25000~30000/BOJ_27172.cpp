//수 나누기 게임 - 골드 5

#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<vector<int>> divisor;
set<int> s;
map<int, int> cnt;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    v.assign(n, 0);
    divisor.assign(n, vector<int>());

    for (int i = 0; i < n; i++){
        cin >> v[i];
        s.insert(v[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= v[i]; j++) {
            if (v[i] % j == 0) {
                divisor[i].push_back(j);
                if (j*j != v[i]) divisor[i].push_back(v[i] / j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j : divisor[i]) {
            // 약수 셋에서 발견 시
            if (s.find(j) != s.end()) {
                cnt[v[i]]--;
                cnt[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << cnt[v[i]] << ' ';
    }
}