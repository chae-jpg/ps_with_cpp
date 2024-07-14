#include <iostream>

using namespace std;

int main() {
    int s, k;
    unsigned long long answer = 1;

    cin >> s >> k;

    for (int i = 0; i < k; i++) {
        if (i < s%k) answer *= (s/k) + 1;
        else answer *= (s/k);
    }

    cout << answer;
}