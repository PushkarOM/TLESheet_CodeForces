#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<ll> arr(n);

        for (auto &x : arr)
            cin >> x;

        sort(arr.begin(), arr.end());

        // prefix[i] = sum of arr[0 ... i-1]
        vector<ll> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        ll total = prefix[n];
        ll ans = LLONG_MIN;

        // x = number of operations removing 2 minimums
        for (int x = 0; x <= k; x++) {

            // Remove first 2*x elements
            ll removeMin = prefix[2 * x];

            // Remaining maximum deletions
            int maxDeletes = k - x;

            // Remove last maxDeletes elements
            ll removeMax = prefix[n] - prefix[n - maxDeletes];

            ll remaining = total - removeMin - removeMax;

            ans = max(ans, remaining);
        }

        cout << ans << '\n';
    }

    return 0;
}

// Sort the array so all minimum elements are on the left and maximums on the right.
// Instead of greedily choosing which operation to perform, try every possible
// number of "delete 2 minimums" operations. If we use it x times, then the
// remaining k-x operations must delete maximums.
// Therefore, we remove the first 2*x elements and the last k-x elements.
// Prefix sums let us get the sum of these removed elements in O(1), so all
// k+1 possibilities can be checked in O(k) after sorting.
// Overall complexity: O(n log n).