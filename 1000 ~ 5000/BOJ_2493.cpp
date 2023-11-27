//탑 - 골드 5

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> h, ans;
    stack<int> s;
    cin >> n;
    h.assign(n+1, 0);
    ans.assign(n+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    s.push(n);

    for (int i = n-1; i >= 1; i--) {
        while (!s.empty() && h[i] >= h[s.top()]) {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }

}



