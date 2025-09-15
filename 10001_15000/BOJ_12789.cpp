// 도키도키 간식드리미 - 실버 3

#include <bits/stdc++.h>

using namespace std;

string solve(int n, vector<int>& v) {

    stack<int> small, large;
    small.push(0);
    large.push(n+1);
    for (int i = 0; i < n; i++) {
        int j = v[i];

        if (j == small.top() + 1) {
            small.push(j);

            while (!large.empty() && large.top() == small.top() + 1) {
                small.push(large.top());
                large.pop();
            }

        } else {
            if (large.top() < j) return "Sad";
            large.push(j);
        }
    }
    return "Nice";
}

int main() {
    int n;
    vector<int> v;
    cin >> n;
    v.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << solve(n, v);
}