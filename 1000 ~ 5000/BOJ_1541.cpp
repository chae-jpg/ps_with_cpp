// 일허버린 괄호 - 실버 2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> tokenizer (string& str) {
    vector<string> arr;
    str.insert(str.length(), "+");

    int pos = 0;

    while ((pos = str.find_first_of("+-")) != string::npos) {
        arr.push_back(str.substr(0, pos));
        arr.push_back(string(1, str[pos]));
        str.erase(0, pos + 1);
    }
    return arr;
}

int main() {
    string str;
    int answer = 0;
    bool add = true;

    cin >> str;

    vector<string> arr = tokenizer(str);

    for (auto s : arr) {
        if (s == "-") {
            add = false;
            continue;
        } else if (s == "+") {
            continue;
        }
        else {
            int t = stoi(s);
            if (add) answer += t;
            else answer -= t;
        }
    }
    cout << answer;
}