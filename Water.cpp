#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> H(N);
        for (int i = 0; i < N; i++) cin >> H[i];

        int l = 0, r = N - 1;
        int max_height = 0, left_idx = 0, right_idx = N - 1;
        while (l < r) {
            int cur_height = min(H[l], H[r]);
            if (cur_height > max_height) {
                max_height = cur_height;
                left_idx = l;
                right_idx = r;
            }
            if (H[l] < H[r]) l++;
            else r--;
        }
        cout << left_idx << " " << right_idx << endl;
    }
    return 0;
}