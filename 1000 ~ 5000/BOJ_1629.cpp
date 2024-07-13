#include <iostream>

using namespace std;

long long a, b, c;

long long exp(long long x, long long n) {
    if (!n) return 1;
    long long u = exp(x, n/2);
    u = (u * u) % c;
    if (n%2) u = (u*x)%c;
    return u;
}

int main() {

    cin >> a >> b >> c;

    cout << exp(a, b);
}