//배 - 골드 5

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    vector<int> crane, box;
    cin >> n;
    crane.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> crane[i];
    }
    sort(crane.begin(), crane.end());
    cin >> m;
    box.assign(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> box[i];
    }
    sort(box.begin(), box.end());

    //가장 무거운 박스의 무게가 크레인의 무게 제한보다 클 때 -> 옮길 수 없음.
    if (box[m-1] > crane[n-1]) {
        cout << -1;
        return 0;
    }

    int l = 0, r = box.size()-1, cnt = 0;

    while (l <= r) {
        int l_c = 0, r_c = n-1;

        while (box[r] <= crane[r_c] && r_c >= 0 && r >= 0) {
            r--; r_c--;
        }
        if (r_c < 0) {
            cnt++;
            continue;
        }
        while (box[l] <= crane[l_c] && l_c <= r_c && l < n) {
            l++; l_c++;
        }
        cnt++;
    }
    cout << cnt;

}