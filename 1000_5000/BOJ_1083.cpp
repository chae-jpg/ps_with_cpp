//소트 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int n, s;
vector<int> arr;

void solve() {
    for (int i = 0; i < n-1; i++) {

        int idx = 0, max_n = 0;
        for (int j = i+1; j < n; j++) {
            if (j-i > s) break;
            if (arr[j] > arr[i] &&max_n < arr[j]) {
                max_n = arr[j];
                idx = j;
            }
        }
        if (idx) {
            for (int j = idx; j > i; j--) {
                swap(arr[j], arr[j-1]);
            }
            s -= (idx - i);
        }
        if (!s) return;
    }

}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> s;
    solve();

    for (int i : arr) {
        cout << i << ' ';
    }

}