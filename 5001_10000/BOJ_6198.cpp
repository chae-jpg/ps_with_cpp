// 옥상 정원 꾸미기 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int n;
long long answer;
vector<int> h, ans;
stack<int> s;

void solve() {
    s.push(0);
    for (int i = 1; i < n; i++) {
        //다음 빌딩이 높이가 더 높거나 같으면 -> 더 높이가 높은 빌딩이 나올 때까지 pop, 확인할 수 있는 빌딩의 개수 계산 (두 인덱스 차 -1)
        while (!s.empty() && h[s.top()] <= h[i]) {
            answer += (i - s.top()) -1;
            s.pop();
        }
        s.push(i);
    }
    //만약 스택이 남아있으면 : 높이가 내림차순으로 정럴되어 있는 상태. -> 뒤 인덱스 저장하고 스택이 빌 때까지 하나하나씩 빼줌.
    int t = s.top();
    s.pop();
    while (!s.empty()) {
        answer += (t - s.top());
        s.pop();
    }

}

int main() {
    cin >> n;
    h.assign(n, 0);
    ans.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    solve();
    cout << answer;

}