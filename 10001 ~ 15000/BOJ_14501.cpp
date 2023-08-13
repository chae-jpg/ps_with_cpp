#include <iostream>
#include <vector>

using namespace std;

typedef pair <int, int> pi;

vector<bool> visited;
unsigned long long int answer = 0;

void backtrack(int start, vector<pi>& consulting) {



}

int main() {
    int n;
    vector<pi> consulting;
    cin >> n;
    consulting.assign(n+1, {0, 0});
    visited.assign(n+1, false);

    for (int i = 1; i <= n; i++) {
        cin >> consulting[i].first >> consulting[i].second;
    }

    backtrack(1, consulting);
    cout << answer;


}