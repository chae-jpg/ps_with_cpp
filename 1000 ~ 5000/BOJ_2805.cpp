//나무 자르기 - 실버 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(const vector<int>& tree, int target) {
    int l = 0, r = tree[tree.size()-1];

    while (l<=r) {
        int mid = (l+r) / 2;
        //일단 간당해보이면 자로형 널널하게...
        long long cnt = 0;

        for (int len : tree) {
            len -= mid;
            if (len > 0) cnt += len;
            if (cnt > target) break;
        }

        if (cnt >= target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    int n, m;
    vector<int> tree;
    cin >> n >> m;
    tree.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    sort(tree.begin(), tree.end());
    cout << binarySearch(tree, m);

}