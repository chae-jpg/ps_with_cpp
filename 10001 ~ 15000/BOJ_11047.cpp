#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, cnt = 0, idx = 0;
    vector<int> arr;
    cin >> n >> k;
    arr.assign(n, 0);

    while(n--) {
        cin >> arr[n];
    }

    while (k) {
        while (arr[idx] <= k) {
            k -= arr[idx];
            cnt++;
        }
        idx++;
    }
    cout << cnt;

}