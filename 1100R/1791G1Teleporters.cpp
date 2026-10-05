#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;

        vector<ll> cost(n);

        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            
            // adding cost to reach each teleporter
            cost[i] = (i + 1) + a;
        }

        sort(cost.begin(), cost.end());

        int ans = 0;

        for (ll c : cost) {
            if (k < c)
                break;

            k -= c;
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
