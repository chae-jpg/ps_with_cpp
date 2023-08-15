#include <iostream>
#include <stack>

using namespace std;

string checkString(string& s, stack<char>& stk) {
    string answer = "";
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (s[i] == '<') {
            while (s[i] != '>') {
                answer += s[i];
                i++;
            }
            answer += s[i];
            continue;
        }
        else if (s[i] == ' ') {
            answer += ' ';
            continue;
        }
        else {
            while (s[i] != '<' && s[i] != ' ' && i < len) {
                stk.push(s[i]);
                i++;
            }
            i--;
            while (!stk.empty()) {
                answer += stk.top();
                stk.pop();
            }
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