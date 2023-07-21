#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int main() {
    int n, max_cnt = 0;
    vector<pi> arr;
    cin >> n;
    arr.assign(n, {0, 0});

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int temp_cnt = 1, idx = i, pre_idx = i;
        while(1) {
            while (arr[pre_idx].second > arr[idx].first && idx < n-1) {
                idx++;
            }
            temp_cnt++;
            pre_idx = idx;
            if (idx >= n-1) {
                break;
            }
        }
        max_cnt = max(temp_cnt, max_cnt);
    }
    cout << max_cnt;
}