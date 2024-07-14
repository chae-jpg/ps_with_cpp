#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> answer;
vector<bool> visited;

void backtrack(int cnt, int m, int n) {
    if (cnt == m) {
        for (int a : answer) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        if (i && arr[i] == arr[i-1] && !visited[i-1]) continue;
        visited[i] = true;
        answer[cnt] = arr[i];
        backtrack(cnt+1, m, n);
        visited[i] = false;
    }
}

int main() {
    int n, m;

    cin >> n >> m;
    arr.assign(n, 0);
    visited.assign(n, false);
    answer.assign(m, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    backtrack(0, m, n);
}