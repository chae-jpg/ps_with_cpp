//집합의 표현 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int n, m, a, b, c;
vector<int> arr;

int find(int x) {
    if (x == arr[x]) return x;
    return arr[x] = find(arr[x]);
}

void solve() {
    //union
    if (!a) {
        int x = find(b);
        int y = find(c);
        arr[y] = x;
        return;
    }
    //find
    int x = find(b);
    int y = find(c);
    if (x==y) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n+1, 0);
    for (int i = 0; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        solve();
    }
}