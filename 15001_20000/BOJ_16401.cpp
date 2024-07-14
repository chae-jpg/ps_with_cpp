#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int l = 1, r = arr[arr.size()-1];

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;

        for (int n : arr) {
            cnt += n / mid;
        }

        if (cnt >= target) l = mid + 1;
        else r = mid - 1;

    }
    if (l == arr.size()) return 0;
    return l - 1;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    vector<int> arr;

    cin >> m >> n;
    arr.assign(n, 10);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    cout << binarySearch(arr, m);
}