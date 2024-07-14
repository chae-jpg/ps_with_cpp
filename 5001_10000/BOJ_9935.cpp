//문자열 폭발 - 골드 4

#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str, target;
    stack<char> ans, t;
    stack<int> check;
    cin >> str >> target;
    int t_l = target.length();

    for (char c : str) {
        if (c == target[t_l-1]) {
            for (int i = t_l-2; i >= 0; i--) {
                if (!ans.empty() && ans.top() == target[i]) {
                    t.push(ans.top());
                    ans.pop();
                }
                else {
                    while (!t.empty()) {
                        ans.push(t.top());
                        t.pop();
                    }
                    ans.push(c);
                    break;
                }
            }
            if (!t.empty() && t.size() == t_l-1) {
                while (!t.empty()) t.pop();
            }
        } else {
            ans.push(c);
        }
    }
    if (ans.empty()) {
        cout << "FRULA";
        return 0;
    }

    while (!ans.empty()) {
        t.push(ans.top());
        ans.pop();
    }
    while (!t.empty()) {
        cout << t.top();
        t.pop();
    }

}