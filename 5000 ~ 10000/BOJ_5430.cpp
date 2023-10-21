//AC - 골드 5

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void split(string& str, vector<int>& arr) {
    int pos = 0;
    str.erase(str.begin());

    while ((pos = str.find_first_of("[,]")) != string::npos) {
        string s = str.substr(0, pos);
        str.erase(0, pos+1);
        arr.push_back(stoi(s));
    }
}

string oper(string& func, vector<int>& arr) {
    string answer = "";
    for (auto c : func) {
        if (c == 'R') {
            reverse(arr.begin(), arr.end());
        } else {
            if (arr.empty()) {
                answer = "error";
                return answer;
            } else {
                arr.erase(arr.begin());
            }
        }
    }
    answer += '[';

    if (!arr.empty()) {
        for (int i : arr) {
            answer += to_string(i);
            answer += ",";
        }
    }
    answer.erase(answer.end() - 1);
    answer += "]";
    return answer;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        int temp;
        string func, str;
        vector<int> arr;

        cin >> func;
        cin >> temp;
        cin >> str;
        if (temp) split(str, arr);
        cout << oper(func, arr) << '\n';
    }
}