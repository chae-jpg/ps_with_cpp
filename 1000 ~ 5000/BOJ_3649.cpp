//로봇 프로젝트 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int ans_l = -1, ans_r = -1;
void binarySearch(int x, const vector<int>& len) {
    int l = 0, r = len.size() - 1;
    long long sum = 0;
    while (l < r) {
        sum = len[l] + len[r];
        if (sum == x) {
            ans_l = l; ans_r = r;
            return;
        }
        if (sum < x) {
            l++;
        } else {
            r--;
        }
    }
    return;
}

int main() {
    int x, n;
    vector<int> len;
    while (cin >> x >> n) {
        ans_l = -1, ans_r = -1;
        x *= 1e7;
        len.assign(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> len[i];
        }
        sort(len.begin(), len.end());
        binarySearch(x, len);
        if (ans_l < 0) cout << "danger";
        else {
            cout << "yes " << len[ans_l] << ' ' << len[ans_r];
        }
    }

}