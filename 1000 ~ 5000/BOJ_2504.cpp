//괄호의 값 - 골드 5

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    stack<int> num;
    stack<char> bracket;
    bool flag = false;
    cin >> s;

    for (char c : s) {
        if (c == '(' || c == '[') {
            bracket.push(c);
            flag = false;
            continue;
        }
        if (c == ')') {
            if (bracket.top() != '(') {
                cout << 0;
                return 0;
            }
            int sum = 0;
            if (flag) {
                sum += num.top();
                num.pop();
            }
            (sum) ? num.push(sum*2) : num.push(2);
            flag = true;
            continue;
        }
        if (c == ']') {
            if (bracket.top() != '[') {
                cout << 0;
                return 0;
            }
            int sum = 0;
            if (flag) {
                sum += num.top();
                num.pop();
            }
            (sum) ? num.push(sum*3) : num.push(3);
            flag = true;
            continue;
        }
    }
    int sum = 0;

    while(!num.empty()) {
        sum += num.top();
        num.pop();
    }
    cout << sum;
}