//쿼드트리 - 실버 1

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

string answer = "";

void quadtree(int n, const vector<vector<char>>& tree, pi l) {
    char cmp = tree[l.first][l.second];

    for (int i = l.first; i < l.first + n; i++) {
        for (int j = l.second; j < l.second + n; j++) {
            if (tree[i][j] != cmp) {
                answer += '(';
                quadtree(n/2, tree, l);
                quadtree(n/2, tree, {l.first, l.second + n/2});
                quadtree(n/2, tree, {l.first + n/2, l.second});
                quadtree(n/2, tree, {l.first + n/2, l.second + n/2});
                answer += ')';
                return;
            }
        }
    }
    answer += cmp;

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

    quadtree(n, tree, {0, 0});
    cout << answer;
}