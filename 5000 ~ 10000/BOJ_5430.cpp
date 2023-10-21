//AC - 골드 5

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

deque<int> d;

void split(string& str) {
    string num = "";
    for (auto c : str) {
        switch (c) {
            case '[' :
                break;
            case ',' : case ']' :
                d.push_back(stoi(num));
                num.clear();
                break;
            default :
                num += c;
        }
    }
}

void oper(string& func) {
    string answer = "";
    bool r_flag = false;

    for (auto c : func) {
        if (c == 'R') {
            r_flag = !r_flag;
        } else {
            if (d.empty()) {
                answer = "error";
                cout << answer << '\n';
                return;
            }
            if (r_flag) d.pop_back();
            else d.pop_front();
        }
    }
    if (d.empty()) {
        answer = "[]";
        cout << answer << '\n';
        return;
    }
    cout << "[";

    if (!r_flag) {
        for (auto iter = d.begin(); iter != d.end() -1; iter++) {
            cout << to_string(*iter) << ',';
        }
        cout << to_string(d.back());
    } else {
        for (auto iter = d.rbegin(); iter != d.rend() -1; iter++) {
            cout << to_string(*iter) << ',';
        }
        cout << to_string(d.front());
    }


    cout << ']' << '\n';
    return;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        d.clear();
        string p;
        int n;
        char c;
        string str;

        cin >> p >> n >> c >> str;

        if (n) split(str);
        oper(p);
    }
}