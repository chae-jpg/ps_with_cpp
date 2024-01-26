//수 묶기 - 골드 4

#include <bits/stdc++.h>

using namespace std;

vector<int> pos, neg;

int main() {
    int n, ans = 0, z_cnt = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 1) {
            ans += a;
        }
        else if (a == 0) z_cnt++;
        else if (a < 0) neg.push_back(a);
        else pos.push_back(-a);
    }

    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    int len = neg.size();
    for (int i = 0; i < len/2; i++) {
        ans += neg[i*2]*neg[(i*2+1)];
    }
    //음수의 개수가 홀수일 때 -> 0이 있으면 없애주기 -> 없으면 가장 큰 수 하나 마저 더해주기
    if (len%2 && !z_cnt) {
        ans += neg[len-1];
    }

    len = pos.size();
    for (int i = 0; i < len/2; i++) {
        ans += pos[i*2]*pos[(i*2+1)];
    }
    //양수의 개수가 홀수일 때 -> 가장 작은 수 하나 마저 더해주기
    if (len%2) ans -= pos[len-1];

    cout << ans;

}