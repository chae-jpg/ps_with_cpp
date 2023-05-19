#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s, cnt = 0;
    vector<int> cow;
    cin >> n >> s;
    cow.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> cow[i];
    }
    sort(cow.begin(), cow.end());

    int left = 0, right = n-1;

    while (right != 0) {
        if (left != right && cow[left] + cow[right] <= s) {
            left++;
            cnt++;
        } else {
            right--;
            left = 0;
        }
    }

    cout << cnt;
}
