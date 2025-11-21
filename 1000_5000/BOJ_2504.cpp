//괄호의 값 - 골드 5

#include <bits/stdc++.h>

using namespace std;

string str;
stack<string> s;

int solve() {

    for (char c : str) {
        // 1. 여는 괄호
        if (c == '(' || c == '[') {
            string s_in = "";
            s.push(s_in + c);
        }

        // 2. 닫는 괄호
        else if (c == ')') {
            if (s.empty()) return 0;
            string t = s.top();

            if (t == "(") {
                s.pop();
                s.push("2");
            }
            else if (t == "[") return 0;

            else {
                int sum = 0;
                while (s.size() >= 2 && isdigit(t[0])) {
                    int tmp = stoi(t);
                    sum += tmp;
                    s.pop();
                    t = s.top();
                }
                if (t[0] == '(') {
                    s.pop();
                    s.push(to_string(sum*2));
                }
                else return 0;
            }
        }
        else if (c == ']') {
            if (s.empty()) return 0;
            string t = s.top();

            if (t == "[") {
                s.pop();
                s.push("3");
            }
            else if (t == "(") return 0;

            else {
                int sum = 0;
                while (s.size() >= 2 && isdigit(t[0])) {
                    int tmp = stoi(t);
                    sum += tmp;
                    s.pop();
                    t = s.top();
                }
                if (t[0] == '[') {
                    s.pop();
                    s.push(to_string(sum*3));
                }
                else return 0;
            }
        }
    }

    int ans = 0;

    while (!s.empty()) {
        string t = s.top();
        if (!isdigit(t[0])) return 0;
        ans += stoi(t);
        s.pop();
    }
    return ans;
}

int main() {

    cin >> str;

    cout << solve();
}