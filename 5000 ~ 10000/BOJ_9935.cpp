//문자열 폭발 - 골드 4

#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str, target;
    stack<char> ans, t;
    stack<int> check;
    cin >> str >> target;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == target[0]) {
            if (target.length() == 1) continue;
            check.push(0);
            ans.push(str[i]);
            continue;
        }
        ans.push(str[i]);

        if (!check.empty()) {
            if (target[check.top()+1] == str[i]) check.push(check.top()+1);
            else {
                while(check.top()) {
                    check.pop();
                }
                check.pop();
            }
        }
        if (!check.empty() && check.top() == target.length()-1) {
            for (int j = 0; j < target.size(); j++) ans.pop();
            while(check.top()) check.pop();
            check.pop();
        }
    }
    if (ans.empty()) {
        if (check.empty()) cout << "FRULA";
        else {
            while (!check.empty()) {
                t.push(target[check.top()]);
                check.pop();
            }
            while (!t.empty()) {
                cout << t.top();
                t.pop();
            }
        }
    } else {
        while (!ans.empty()) {
            t.push(ans.top());
            ans.pop();
        }
        while (!t.empty()) {
            cout << t.top();
            t.pop();
        }
    }

}