//나도리팡 - 골드 5

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, t, idx = 0;
    long long sum = 0;
    long long total_t = 0;
    vector<int> arr;
    cin >> n >> k >> t;
    arr.assign(n, 0);
    int temp = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (sum >= k) {
            for (int j = idx; j <= i - 1; j++) {
                temp += arr[j];
            }
            total_t += temp;
            arr[i] = arr[i] + temp - k;
            sum = arr[i];
            temp = arr[i];
            idx = i + 1;
        }
    }
    if (!sum && total_t <= t) cout << "YES";
    else cout << "NO";
}