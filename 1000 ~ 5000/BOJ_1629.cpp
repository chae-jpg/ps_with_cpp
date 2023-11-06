#include <iostream>

using namespace std;

long long a, b, c;

long long exp(long long x, long long n) {
    if (!n) return 1;
    if (!(n % 2)) {
        return exp(x*x%c, n/2);
    }
    return exp(x*x%c, (n-1)/2);
}

int main() {

    cin >> a >> b >> c;

    cout << exp(a, b);
}