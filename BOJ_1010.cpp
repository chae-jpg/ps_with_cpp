#include <iostream>

using namespace std;

long long fact(int n) {
    if (n == 1) return 1;
    return n * fact(n-1);
}

long long comb(int n, int m) {
    return fact(n) / (fact(n-m) * fact(m));
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, m;
        cin >> n >> m;
        if (n == m) cout << 1 << '\n';
        else cout << comb(m, n) << '\n';
    }
}