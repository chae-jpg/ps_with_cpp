#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;

void backtrack(int cnt, int n, int m, int front) {
    if (cnt == m) {
        for (int a : answer) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = front; i <= n; i++) {
        answer[cnt] = i;
        backtrack(cnt+1, n, m, i);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    answer.assign(m, 0);

    backtrack(0, n, m, 1);

}