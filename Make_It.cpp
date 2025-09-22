#include <bits/stdc++.h>
using namespace std;

bool canReach(int N) {
    // Try to reach N from 1 by reversing the operations
    while (N > 1) {
        if (N % 2 == 0) {
            N /= 2;
        } else if ((N - 3) >= 1) {
            N -= 3;
        } else {
            return false;
        }
    }
    return N == 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << (canReach(N) ? "YES" : "NO") << endl;
    }
    return 0;
}