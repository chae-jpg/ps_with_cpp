#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int main() {
    int n, cnt = 0, low = 500000, idx = 0;
    cin >> n;

    vector<pi> arr(n, {0, 0});

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    for (int i = n-1; i >= 0; i--) {
        if (arr[i].second == i) continue;
        if (arr[i].second > low) {
            cnt += abs(arr[i].second - low - i - idx);
        } else {
            cnt += abs(arr[i].second - i);
        }
        if (arr[i].second < low) {
            low = arr[i].second;
            idx++;
        }
    }
    cout << cnt;

}