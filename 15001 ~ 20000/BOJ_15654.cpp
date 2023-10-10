#include <iostream>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<bool> visited;
vector<int> answer;

void backtrack(int cnt, int n, int m) {
    if (cnt == m) {
        for (int a : answer) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        answer[cnt] = arr[i];
        visited[i] = true;
        backtrack(cnt + 1, n, m);
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

    backtrack(0, n, m);
}