#include <iostream>

using namespace std;


int recur(int n, int m) {
    if (!n%2 || !m%2) return 0;
    return 1 + 4 * recur(n/2, m/2);
}

int main() {
    int n, m;

    cin >> n >> m;

    cout << recur(n, m);
}