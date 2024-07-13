//숨바꼭질 2 - 골드 4

#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 100000
const int INF = 1e9+7;
bool is_used[MAX_N + 1] = {false}, same_found = false;

int find_time = 0, cnt = 0, time_saved = 0, ans_time = 1e9+7;

void bfs(int n, int k) {
    queue<int> q;
    int top;

    if (n == k) {
        cnt = 1;
        ans_time = 0;
        return;
    }

    q.push(n);
    is_used[n] = true;

    while(!q.empty()) {
        time_saved++;
        if (time_saved > ans_time) break;
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int top = q.front();
            q.pop();
            is_used[top] = true;
            if (top - 1 == k || top + 1 == k || top*2 == k) {
                if (ans_time == INF) ans_time = time_saved;
                cnt++;
                continue;
            }

            if (top - 1 >= 0 && !is_used[top-1]) {
                q.push(top-1);
            }
            if (top + 1 <= MAX_N && !is_used[top+1]) {
                q.push(top+1);
            }
            if (top*2 <= MAX_N && !is_used[top*2]) {
                q.push(top*2);
            }

        }




    }
}

int main() {
    int n, k;
    cin >> n >> k;
    bfs(n, k);
    cout << ans_time << '\n' << cnt;


}