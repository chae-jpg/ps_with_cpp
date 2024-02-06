//가장 긴 증가하는 부분 수열 2 - 골드 2

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    vector<int> v, ans;
    cin >> n;
    v.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    ans.push_back(v[0]);

    for (int i = 1; i < n; i++){
        if (v[i] > ans.back()) {
            ans.push_back(v[i]);
        } else {
            int low = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
            ans[low] = v[i];
        }
    }
    cout << ans.size();
}