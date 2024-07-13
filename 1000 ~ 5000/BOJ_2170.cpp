#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
vector<pi> coor;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        coor.push_back({x, y});
    }

    sort(coor.begin(), coor.end());

    int l = coor[0].first, r = coor[0].second;
    cnt += (r-l);
    for (int i = 1; i < n; i++) {
        int x = coor[i].first, y = coor[i].second;
        if (x > r) {
            l = x, r = y;
            cnt += (r-l);
        }
        else if (y > r) {
            cnt += y-r;
            r = y;
        }

    }
    cout << cnt;
}