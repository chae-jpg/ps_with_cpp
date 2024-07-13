//배너 걸기 - 실버 1

#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m;
    vector<int> height;
    map<int, int> cnt;
    cin >> n >> m;

    int limit = m - m/10;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        height.push_back(t);
    }

    for (int i = 0; i < m; i++) {
        cnt[height[i]]++;
        if (cnt[height[i]] ==limit) {
            cout << "YES";
            return 0;
        }
    }

    for (int i = 0; i < n-m; i++) {
        cnt[height[i]]--;
        cnt[height[i+m]]++;
        if (cnt[height[i+m]]==limit) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

}