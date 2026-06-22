#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n;
        cin >> s;

        vector<int> pref(n), suff(n);

        vector<int> seen(26, 0);
        int distinct = 0;

        // Prefix distinct counts
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            if (!seen[c]) {
                seen[c] = 1;
                distinct++;
            }

            pref[i] = distinct;
        }

        fill(seen.begin(), seen.end(), 0);
        distinct = 0;

        // Suffix distinct counts
        for (int i = n - 1; i >= 0; i--) {
            int c = s[i] - 'a';

            if (!seen[c]) {
                seen[c] = 1;
                distinct++;
            }

            suff[i] = distinct;
        }

        int ans = 0;

        // Try every valid split
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, pref[i] + suff[i + 1]);
        }

        cout << ans << '\n';
    }

    return 0;
}