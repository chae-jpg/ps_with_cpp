#include <iostream>
#include <vector>

using namespace std;

typedef pair<string, int> p;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, t;
    vector<p> arr;
    cin >> n >> m;
    arr.assign(n, {"", 0});

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 0; i < m; i++) {
        cin >> t;
        int l = 0, r = n-1;
        while (l <= r) {
            int mid = (l+r) / 2;
            if (arr[mid].second < t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << arr[l].first << '\n';
    }
}