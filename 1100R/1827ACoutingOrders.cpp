#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<ll> a(n), b(n);

        for (auto &x : a)
            cin >> x;

        for (auto &x : b)
            cin >> x;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ll ans = 1;

        // Process b from largest to smallest.
        // Larger b[i] has fewer possible elements in a,
        // so we handle these restrictive positions first.
        for (int i = n - 1; i >= 0; i--) {

            // Find the first element in a that is strictly greater than b[i].
            // Therefore, all elements from pos to n-1 can satisfy b[i].
            int pos = upper_bound(a.begin(), a.end(), b[i]) - a.begin();

            // Total elements of a that can satisfy b[i].
            int valid = n - pos;

            // (n - 1 - i) elements of a have already been assigned
            // to the larger b values processed before this one.
            int used = n - 1 - i;

            // Only unused valid elements can be chosen for this position.
            int choices = valid - used;

            if (choices <= 0) {
                ans = 0;
                break;
            }

            // Each valid choice gives a different final permutation.
            ans = (ans * choices) % MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}

