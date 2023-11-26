#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, t, s_top, i;
    stack<int> s;
    vector<int> v, answer;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> t;
        s.push(t);
    }

    while(!s.empty()) {
        s_top = s.top();
        s.pop();
        if (v.empty()) {
            answer.push_back(-1);
            v.push_back(s_top);
            continue;
        }
        int v_len = v.size()-1;
        for (i = v_len; i >= 0; i--) {
            if (s_top < v[i]) {
                answer.push_back(v[i]);
                break;
            }
        }
        if (i == -1) {
            answer.push_back(-1);
        }
        v.push_back(s_top);
    }
    int answer_len = answer.size()-1;
    for (int n = answer_len; n>= 0; n--) {
        cout << answer[n] << ' ';
    }

}