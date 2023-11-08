#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int>& time, int l, int r, int m) {
    while (l <= r) {
        int cnt = 0, mid = (l + r) / 2, sum = 0;

        for (int i = 0; i < time.size(); i++) {
            if (sum + time[i] > mid) {
                cnt++;
                sum = 0;
            }
            sum += time[i];
        }
        cnt++;

        if (cnt <= m) {
            r = mid -1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    int n, m, sum = 0, max_time = 0;
    vector<int> time;

    cin >> n >> m;
    time.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> time[i];
        sum += time[i];
        max_time = max(max_time, time[i]);
    }

    cout << binarySearch(time, max_time, sum, m);


}