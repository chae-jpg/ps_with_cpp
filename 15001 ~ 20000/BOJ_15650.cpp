#include <iostream>
#include <vector>

using namespace std;

vector<bool> visited;
vector<int> answer;

void backtrack(int n, int m, int root, int cnt) {
    if (cnt == m) {
        answer[cnt-1] = root;
        for (int a : answer) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }
    answer[cnt-1] = root;
    visited[root] = true;
    for (int i = root; i <= n; i++) {
        if (visited[i]) {
            continue;
        }
        backtrack(n, m, i, cnt+1);
    }
    visited[root] = false;
}

int main() {
    int n, m;
    cin >> n >> m;
    visited.assign(n+1, false);
    answer.assign(m, 0);

    for (int i = 1; i <= n - m + 1; i++) {
        backtrack(n, m, i, 1);
    }
}