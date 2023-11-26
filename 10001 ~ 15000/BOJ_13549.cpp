//숨바꼭질 3 - 골드 5

#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 100000

bool visited[MAX_N + 1] = {false};

int bfs(int n, int k) {
    int cnt = 0;
    queue<int> q;
    if (!n) q.push(n);
    else {
        while (n <= MAX_N) {
            if (n == k) return cnt;
            visited[n] = true;
            q.push(n);
            n *= 2;
        }
    }
    while (!q.empty()) {
        cnt++;
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int top = q.front();
            if (top == k) return cnt- 1;
            q.pop();
            if (top + 1 <= MAX_N && !visited[top + 1]) {
                visited[top + 1] = true;
                q.push(top + 1);
                int t = top + 1;
                while (t*2 <= MAX_N) {
                    if (!visited[t*2]) {
                        if (t*2 == k) return cnt;
                        visited[t*2] = true;
                        q.push(t*2);
                    }
                    t*=2;
                }
            }
            if (top -1 >= 0 && !visited[top -1]) {
                visited[top - 1] = true;
                q.push(top - 1);
                int t = top-1;
                if (t) {
                    while (t*2 <= MAX_N) {
                        if (!visited[t*2]) {
                            if (t*2 == k) return cnt;
                            visited[t*2] = true;
                            q.push(t*2);
                        }
                        t*=2;
                    }
                }
            }
            if (top) {
                while (top*2 <= MAX_N) {
                    if (!visited[top*2]) {
                        if (top*2 == k) return cnt;
                        visited[top*2] = true;
                        q.push(top*2);
                    }
                    top*=2;
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k);
}