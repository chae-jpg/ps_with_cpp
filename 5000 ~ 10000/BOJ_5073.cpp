#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string checkTriangle(vector<int>& v) {
    if (v[0] + v[1] <= v[2]) return "Invalid\n";
    if (v[0] == v[1] == v[2]) return "Equilateral\n";
    if (v[0] != v[1] != v[2]) return "Scalene\n";
    return "Isosceles\n";
}

int main() {
    int a, b, c;
    while (cin >> a >> b >> c && a != 0) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        cout << checkTriangle(v);
    }
}