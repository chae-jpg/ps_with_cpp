//트리의 지름 - 골드 4

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int v;
vector<vector<pi>> tree;
vector<int> len;
vector<bool> visited;

void calcLen(int n) {
    int cnt = 0;
    visited[n] = true;
    for (auto i : tree[n]) {
        if (visited[i.first]) continue;
        if (!len[i.first]) calcLen(i.first);
        cnt = max(len[i.first] + i.second, cnt);
    }
    len[n] = cnt;
}

int calcDia(int n) {
    visited[n] = true;
    int ans = 0;
    int max1 = 0, max2 = 0;
    for (auto i : tree[n]) {
        if (visited[i.first]) continue;
        if (len[i.first] + i.second > max1) {
            max2 = max1;
            max1= len[i.first] + i.second;
        }
        else if (len[i.first] + i.second > max2) {
            max2 = len[i.first] + i.second;
        }
    }
    int max_child_d = 0;
    for (auto i : tree[n]) {
        if (visited[i.first]) continue;
        max_child_d = max(max_child_d, calcDia(i.first));
    }
    return max(max_child_d, max1+max2);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> v;
    tree.assign(v+1, vector<pi>());

    for (int i = 0; i < v-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b,c});
        tree[b].push_back({a, c});
    }
    visited.assign(v+1, false);
    len.assign(v+1, 0);
    calcLen(1);
    visited.assign(v+1, false);
    cout << calcDia(1);

}