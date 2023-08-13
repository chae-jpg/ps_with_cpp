#include <iostream>

using namespace std;

int adder = 1;
int sum = 0;

void recur(int n, int m) {
    if ((n%2 == 0 || m%2 == 0) || (n == 0 || m == 0)) return;
    sum += adder;
    adder *= 4;
    return recur((n-1)/2, (m-1)/2);
}


int main() {
    int n, m;

    cin >> n >> m;

    recur(n, m);

    cout << sum;

}