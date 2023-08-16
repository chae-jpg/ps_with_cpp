#include <iostream>
#include <vector>

using namespace std;

int main() {
    int s, k;
    unsigned long long answer = 1;

    cin >> s >> k;

    vector<int> arr(k, s/k);
    int remain = s % k;

    for (int i = 0; i < remain; i++) {
        arr[i]++;
    }

    for (int n : arr) {
        answer *= n;
    }
    cout << answer;
}