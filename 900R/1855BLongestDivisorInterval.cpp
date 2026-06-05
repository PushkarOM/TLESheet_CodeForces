#include<bits/stdc++.h>
using namespace std;

// Let Lk = lcm(1, 2, ..., k).
//
// An interval [l, r] is valid if every number in it divides n.
// This is equivalent to saying lcm(l, l+1, ..., r) divides n.
//
// For any interval of length k, its LCM is at least Lk,
// so a valid interval of length k exists iff Lk divides n.
//
// Therefore, the answer is the largest k such that n % Lk == 0.
//
// Since Lk grows very quickly and exceeds 1e18 after only a few dozen terms,
// we precompute all Lk once and, for each test case, find the largest one
// that divides n.

int main()
{
    
    const unsigned long long LIMIT = 1000000000000000000ULL;

    // Precompute Lk = lcm(1,2,...,k)
    vector<unsigned long long> lcms;
    unsigned long long cur = 1;

    for (unsigned long long k = 1;; k++) {
        unsigned long long g = gcd(cur, k);

        // Check if (cur / g) * k would exceed LIMIT
        if (cur / g > LIMIT / k)
            break;

        cur = (cur / g) * k;
        lcms.push_back(cur);
    }

    int t;
    cin >> t;

    while (t--) {
        unsigned long long n;
        cin >> n;

        int ans = 0;

        for (auto x : lcms) {
            if (n % x == 0)
                ans++;
            else
                break;
        }

        cout << ans << '\n';
    }
    return 0;
}