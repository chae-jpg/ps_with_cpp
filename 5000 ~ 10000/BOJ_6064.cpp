#include <iostream>

using namespace std;

int getGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        int m, n, x, y, gcd;
        cin >> m >> n >> x >> y;

        gcd = getGcd(max(m, n), min(m, n));
        int cal = 0;

        while (cal < n/gcd) {
            int num = m*cal+x;
            if (num % n == y || (num % n == 0) && (y == n)) {
                cout << num << '\n';
                break;
            }
            cal++;
        }
        if (cal == n/gcd) {
            cout << -1 << '\n';
        }
    }
}