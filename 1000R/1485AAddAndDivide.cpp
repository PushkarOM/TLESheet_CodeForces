#include <bits/stdc++.h>
using namespace std;

// Instead of considering every possible sequence of operations,
// observe that if we decide to increase 'b' k times, it is always
// optimal to perform all increments before any division.
// Therefore, we only need to try different values of k.
//
// For each k:
//   1. Set divisor = b + k.
//   2. Simulate repeated divisions until a becomes 0.
//   3. Total operations = k (increments) + divisions.
//
// Since a <= 1e9, the number of divisions is at most ~30 (when b = 2),
// so trying around 35-40 possible increments is sufficient.

int main() {

    int t;
    cin >> t;

    while (t--) {
        long long a, b;
        cin >> a >> b;

        int ans = INT_MAX;

        int start = (b == 1 ? 1 : 0);

        for (int k = start; k <= start + 35; k++) {
            long long curA = a;
            long long curB = b + k;

            int divs = 0;

            while (curA > 0) {
                curA /= curB;
                divs++;
            }

            ans = min(ans, k + divs);
        }

        cout << ans << '\n';
    }

    return 0;
}
