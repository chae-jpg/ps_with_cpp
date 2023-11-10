#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (arr[mid] == target) return 1;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    vector<int> arr;
    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    cin >> m;
    while (m--) {
        int t;
        cin >> t;
        cout << binarySearch(arr, t) << ' ';

    }


}