#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n, m, input, cnt;
    cin >> t;

    while (t--) {
        cnt = 0;
        cin >> n >> m;
        queue<int> q;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            cin >> input;
            q.push(input);
            v.push_back(input);
        }
        sort(v.begin(), v.end());

        while (true) {
            if(q.front() == v[v.size() - 1]) {
                cnt++;
                q.pop();
                v.pop_back();
                if (m == 0) {
                    break;
                }
            }
            else {
                q.push(q.front());
                q.pop();
            }
            m = (m == 0) ? q.size()-1 : m - 1;
        }       
        cout << cnt << '\n';
    }





}