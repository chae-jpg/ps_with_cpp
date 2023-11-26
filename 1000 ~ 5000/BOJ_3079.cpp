//입국심사 - 골드 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll binarySearch(const vector<ll>& time, ll l, ll r, ll m) {
    while (l <= r) {
        ll mid = (l+r) / 2;
        ll cnt = 0;
        for (int i = 0; i < time.size(); i++) {
            cnt += mid / time[i];
            if (cnt > m) {
                break;
            }
        }
        if (cnt >= m) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }

    }
    return l;
}

int main() {
    ll n, m;
    vector<ll> time;

    cin >> n >> m;
    time.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    sort(time.begin(), time.end());

    cout << binarySearch(time, 0, time[0]*m, m);

}