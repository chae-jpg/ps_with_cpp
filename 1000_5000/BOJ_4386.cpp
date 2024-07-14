//별자리 만들기 - 골드 3

#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> p;

int n;
vector<int> link, len;
vector<p> coor;

int find(int v) {
    while (link[v] != v) v = link[v];
    return v;
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (len[a] < len[b]) swap(a, b);
    link[b] = a;
    len[a] += len[b];
}

double solve() {
    double sum = 0;
    vector<vector<double>> edge;
    link.assign(n, 0);
    len.assign(n, 0);

    for (int i = 0; i < n; i++) link[i] = i;

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            p a = coor[i], b = coor[j];
            double w = sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
            edge.push_back({w, (double)i, (double)j});
        }
    }

    sort (edge.begin(), edge.end());

    for (auto i : edge) {
        int a = i[1], b = i[2];
        double w = i[0];
        if (find(a)!=find(b)) {
            unite(a, b);
            sum += w;
        }
    }
    return sum;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        double a, b; cin >> a >> b;
        coor.push_back({a, b});
    }

    printf("%.2f", solve());

}