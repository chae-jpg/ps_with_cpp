//인간-컴퓨터 상호작용 - 실버 1

#include <bits/stdc++.h>

using namespace std;

string str;
vector<vector<int>> cnt;

void solve() {
    cnt[str[0]-'a'][0]++;
    for (int i = 1; i < str.length(); i++) {
        for (int j = 0; j < 26; j++) {
            cnt[j][i] = cnt[j][i-1];
        }
        cnt[str[i] - 'a'][i]++;
    }

    int q;
    cin >> q;

    while (q--) {
        char a;
        int n, m;
        cin >> a >> n >> m;
        int answer = cnt[a-'a'][m] - cnt[a-'a'][n];
        if (str[n] == a) answer++;
        cout << answer << '\n';
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> str;
    cnt.assign(26, vector<int> (str.length(), 0));


    solve();

}