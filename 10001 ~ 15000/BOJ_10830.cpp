// 행렬 곱셈 - 골드 4

#include <bits/stdc++.h>

using namespace std;

int n;
long long b;

const int MOD = 1000;

vector<vector<long long>> v, tmp, ans;

void matMul(vector<vector<long long>>& a, vector<vector<long long>>& b) {
    tmp.assign(n, vector<long long> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= MOD;
        }
    }

    a = tmp;

}

vector<vector<long long>> modpow(vector<vector<long long>> v, int n) {
    if (n == 0) return ans;
    vector<vector<long long>> u = modpow(v, n/2);
    matMul(u, u);
    if (n%2) matMul(u, v);
    return u;
}

int main() {
    cin >> n >> b;
    v.assign(n, vector<long long> (n, 0));
    ans.assign(n, vector<long long> (n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
        ans[i][i] = 1;
    }

//    while (b) {
//        if (b%2) {
//            matMul(ans, v);
//        }
//        matMul(v, v);
//        b/=2;
//    }

    vector<vector<long long>> a = modpow(v, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }

}