#include <iostream>
#include <stack>

using namespace std;

string checkString(string& s, stack<char>& stk) {
    string answer = "";
    bool check = false;

    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (s[i] == '<') {
            while (!stk.empty()) {
                answer += stk.top();
                stk.pop();
            }
            check = true;
            answer += s[i];
        } else if (s[i] == '>') {
            check = false;
            answer += s[i];
        } else if (!check) {
            if (s[i] == ' ') {
                while (!stk.empty()) {
                    answer += stk.top();
                    stk.pop();
                }
                answer += s[i];
            } else if (i == len - 1) {
                stk.push(s[i]);
                while (!stk.empty()) {
                    answer += stk.top();
                    stk.pop();
                }
            } else {
                stk.push(s[i]);
            }
        } else if (check) {
            answer += s[i];
        }
    }
    return answer;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    stack<char> stk;

    getline(cin, s);

    cout << checkString(s, stk);

}