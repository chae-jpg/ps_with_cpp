//카드 정렬하기 - 골드 4

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum = 0;
    priority_queue<int> q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        q.push(-a);
    }

    for (int i = 0; i < n-1; i++) {
        int a, b;
        a = q.top(); q.pop();
        b = q.top(); q.pop();
        sum += -(a + b);
        q.push((a + b));
    }
    cout << sum;
}