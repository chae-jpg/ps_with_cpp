#include <iostream>

using namespace std;

//큰 수, 작은 수 순
int recur (int n, int m) {
    if (!m) return 0;
    return n / m + recur (m, n % m);
}

int main() {
    int n, m;

    cin >> n >> m;

    cout << recur(max(n, m), min (n, m));
}