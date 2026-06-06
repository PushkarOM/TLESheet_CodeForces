#include <bits/stdc++.h>

using namespace std;

// A consecutive run of length L ('<<<...' or '>>>...')
// forces L+1 strictly ordered positions, hence at least
// L+1 distinct values are required.
//
// Let M be the longest consecutive run length.
// M+1 values are always sufficient, since every shorter
// run can be embedded within these levels.
//
// Therefore answer = longest_run_length + 1.

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n;
        cin >> s;

        int longest = 1;
        int curr = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                curr = 1;
            }
            longest = max(longest, curr);
        }

        cout << longest + 1 << '\n';
    }

    return 0;
}