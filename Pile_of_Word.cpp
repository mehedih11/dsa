#include <bits/stdc++.h>
using namespace std;

bool isPileOfWord(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;
    string a = s1, b = s2;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << (isPileOfWord(s1, s2) ? "YES" : "NO") << endl;
    }
    return 0;
}