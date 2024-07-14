//이진 검색 트리 - 골드 5

#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;
vector<int> tree;

void inorder(int l, int r) {
    if(l >= r) return;
    int i = l+1;

    while (i < r) {
        if (tree[l] < tree[i]) break;
        i++;
    }

    inorder(l+1, i);
    inorder(i, r);
    cout << tree[l] << '\n';

}

int main() {
    int t;
    for (int i = 0; i < 9; i++) {
        cin >> t;
        tree.push_back(t);
    }

    inorder(0, tree.size()-1);




}