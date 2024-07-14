//행렬 곱셈 - 실버 5

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    vector<vector<long long>> m1, m2;
    cin >> n >> m;
    m1.assign(n, vector<long long> (m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> m1[i][j];
        }
    }

    cin >> m >> k;
    m2.assign(m, vector<long long> (k, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> m2[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            long long n = 0;
            for (int h = 0; h < m; h++) {
                n += m1[i][h] * m2[h][j];
            }
            cout << n << ' ';
        }
        cout << '\n';
    }
}