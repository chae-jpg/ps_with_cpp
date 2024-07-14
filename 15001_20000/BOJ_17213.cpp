#include <iostream>

using namespace std;

int main() {
    int n, m;
    long long answer = 1;
    cin >> n >> m;

    for (int i = m-1; i > n-1; i--) {
        answer = answer * i / (m - i);
    }

    cout << answer;
}