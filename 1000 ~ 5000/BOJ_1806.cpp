#include <iostream>

using namespace std;

const int MAX = 10e6;

int main() {
    int n, s, left = 0, sum, len = MAX + 1;
    int arr[MAX] = {0};
    cin >> n >> s;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        while (sum <= s && i > 0) {
            sum += arr[left--];
        }
        if (sum == s) {
            len = min(len, i - left + 1);
            continue;
        }
        while (sum >= s && i < n-1) {
            sum -= arr[left++];
        }
        if (sum == s) {
            len = min(len, i - left + 1);
            continue;
        }

    }

    if (len == MAX + 1) cout << 0;
    else cout << len;

}