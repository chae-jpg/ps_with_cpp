#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    //왼쪽, 오른쪽 스택
    stack<char> l, r;
    cin >> s;

    for (char c : s) {
        l.push(c);
    }

    int m;
    cin >> m;

    while (m--) {
        char t;
        cin >> t;

        switch (t) {
            case 'L' :
                if (!l.empty()) {
                    r.push(l.top());
                    l.pop();
                }
                break;
            case 'D' :
                if (!r.empty()) {
                    l.push(r.top());
                    r.pop();
                }
                break;
            case 'B' :
                if (!l.empty()) l.pop();
                break;
            default :
                char c;
                cin >> c;
                l.push(c);
        }
    }
    while (!l.empty()) {
        r.push(l.top());
        l.pop();
    }
    while (!r.empty()) {
        cout << r.top();
        r.pop();
    }

}