#include <iostream>
#include <set>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t;
    set<int> s;
    
    cin >> n;
    while(n--) {
        cin >> t;
        s.insert(t);
    }
    
    cin >> m;
    while(m--) {
        cin >> t;
        cout << (s.find(t) != s.end() ? 1 : 0) << '\n'; 
    }
}