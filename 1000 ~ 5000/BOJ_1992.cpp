//쿼드트리 - 실버 1

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

string answer = "(", temp = "";

void quadtree(int n, const vector<vector<char>>& tree, pi l, pi r) {
    if (n == 1) {
        temp += tree[l.first][l.second];
        if (temp.length() == 4) {
            if (temp == "1111") answer += '1';
            else if (temp == "0000") answer += '0';
            else answer += "("+ temp + ")";
            temp.clear();
        }
        return;
    }
    quadtree(n/2, tree, l, {r.first/2, r.second/2});
    quadtree(n/2, tree, {l.first, r.second / 2}, {r.first/2, r.second});
    quadtree(n/2, tree, {r.first/2+1, l.second}, {r.first, r.second/2});
    quadtree(n/2, tree, {r.first/2+1, r.second/2+1}, r);



}

int main() {
    int n;
    vector<vector<char>> tree;

    cin >> n;
    tree.assign(n, vector<char> (n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tree[i][j];
        }
    }

    quadtree(n, tree, {0, 0}, {n-1, n-1});
}