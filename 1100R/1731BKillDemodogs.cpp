#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;
const ll INV6 = 166666668;

/*
    Cell (i, j) contains i * j Demodogs.

    For a 2x2 block:

        (i,j) -> (i,j+1)
          |          |
          v          v
        (i+1,j) -> (i+1,j+1)

    The two possible paths have the same starting and ending
    cells, so we compare:

        i * (j+1)  and  (i+1) * j

    Their difference is:

        i(j+1) - (i+1)j = i - j

    This tells us that the optimal path stays around the
    diagonal, and the resulting maximum sum is:

        n * (n + 1) * (4n - 1) / 6

    The problem asks for:

        maximum_sum * 2022

    Since division by 6 cannot be done normally under modulo,
    we multiply by the modular inverse of 6:

        6^(-1) mod (1e9+7) = 166666668
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll ans = n * (n + 1) % MOD;
        ans = ans * (4 * n - 1) % MOD;
        ans = ans * INV6 % MOD;
        ans = ans * 2022 % MOD;

        cout << ans << '\n';
    }
}