//좋다 - 골드 4

#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> arr;

bool binarySearch(int l, int r, long long target, int idx) {
    while (l < r) {
        int mid = (l+r)/2;

        if (arr[l] + arr[r] == target) {
            if (l != idx && r != idx) return true;
            if (l == idx) l++;
            else if (r == idx) r--;
            continue;
        }
        if (arr[l] + arr[r] > target) r--;
        else l++;
    }
    return false;
}

int solve() {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (binarySearch(0, n-1, arr[i], i)) cnt++;
    }
    return cnt;
}

int main() {
    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cout << solve();

}