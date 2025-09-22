#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> T(max(4, n+1));
    T[0] = 0;
    T[1] = 1;
    T[2] = 1;
    T[3] = 2;
    for (int i = 4; i <= n; i++) {
        T[i] = T[i-1] + T[i-2] + T[i-3] + T[i-4];
    }
    cout << T[n] << endl;
    return 0;
}