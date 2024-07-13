// 탭 UI - 실버 2

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    double screen_len;
    cin >> n;
    vector<double> tap_len(n, 0), sum(n, 0);

    cin >> tap_len[0];
    sum[0] = tap_len[0];
    for (int i = 1; i < n; i++) {
        cin >> tap_len[i];
        sum[i] = sum[i-1] + tap_len[i];
    }

    cin >> screen_len;

    int q; cin >> q;

    for (int i = 0; i < q; i++) {
        int a; cin >> a;
        a--;
        double target = tap_len[a];
        double l = (a == 0) ? 0 : sum[a-1], r = sum[n-1] - sum[a];
        double l_len = l + target / 2.0, r_len = r + target / 2.0;
        if (screen_len >= sum[n-1]) printf("%.2f\n", 0.0);
        else if (l_len <= screen_len / 2.0) printf("%.2f\n", 0.0);
        else if (r_len <= screen_len / 2.0)
            printf("%.2f\n", sum[n-1] - screen_len);
        else {
            printf("%.2f\n", l_len - screen_len / 2.0);
        }
    }

    return 0;
}
