//다각형의 면적 - 골드 5

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pi;

int main() {
    int n;
    cin >> n;
    vector<pi> v;

    for (int i = 0; i < n; i++) {
        long long a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        pi a, b;
        if (i == n-1) {
            a = v[i], b = v[0];
        } else {
            a = v[i], b = v[i+1];
        }
        sum += (a.first * b.second) - (b.first * a.second);
    }

    long double ans = abs((long double)sum) / 2;

    cout << fixed;
    cout.precision(1);
    cout << ans;
}