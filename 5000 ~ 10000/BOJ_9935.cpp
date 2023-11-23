//문자열 폭발 - 골드 4

#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str, target;
    stack<char> l, r;
    cin >> str >> target;

    for (int i = str.length()-1; i >= 0; i--) {
        r.push(str[i]);
    }

    int idx = 0;
    string temp ="";
    bool flag = false;

    while (!r.empty()) {
        if (flag) {
            if (target[++idx] == r.top()) {
                temp += r.top();
            } else {
                temp = "";
                idx = 0;
                flag = false;
            }
        }
        if(r.top() == target[0]) {
            flag = true;
            temp = "";
            temp += r.top();
        }
        if (idx == target.length() - 1) {
            flag = false;
            r.pop();
            for (int i = 0; i < idx; i++) {
                l.pop();
            }
            if (!l.empty() && l.top() == target[0]) {
                r.push(l.top());
                l.pop();
                idx=0;
                continue;
            }
            idx=0;
        }

            if (!r.empty()) {
                l.push(r.top());
                r.pop();
            }
    }
    if (l.empty()) cout << "FRULA";
    else {
        while (!l.empty()) {
            r.push(l.top());
            l.pop();
        }
        while (!r.empty()) {
            cout << r.top();
            r.pop();
        }
    }

}