//이중 우선순위 큐 - 골드 4

#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t, n;

    cin >> t;


    while(t--) {
        map<int, int> m;
        int size = 0;
        cin >> n;
        while(n--) {
            char oper;
            int num;
            cin >> oper >> num;
            if (oper == 'I') {
                m[num]++;
            } else if (oper == 'D') {
                if (num == 1) {
                    if (!m.empty()) {
                        if (m.rbegin()->second == 1) m.erase(--m.end());
                        else m.rbegin()->second--;
                    }
                } else {
                    if (!m.empty()) {
                        if (m.begin()->second == 1) m.erase(m.begin());
                        else m.begin()->second--;
                    }
                }

            }
        }
        if (m.empty()) cout << "EMPTY" << '\n';
        else cout << m.rbegin()->first << ' ' << m.begin()->first << '\n';
    }
}