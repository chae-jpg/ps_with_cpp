//N과 M (3) - 실버 3

#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;

void backtrack(int n, int m, int cnt) {
    if (cnt == m) {
        for (int a : answer) {
            cout << a << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        answer[cnt] = i;
        backtrack(n, m, cnt + 1);
    }

}

int main() {
    int n, m;
    cin >> n >> m;
    answer.assign(m, 0);
    backtrack(n, m, 0);
}