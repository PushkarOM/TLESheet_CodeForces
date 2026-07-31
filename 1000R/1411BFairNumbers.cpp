#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

/*
Approach:
1. For each candidate number starting from n:
   - Compute the LCM of all its non-zero digits.
   - A number is fair iff it is divisible by this LCM.
2. If the current number is not fair, increment it and repeat.

Time Complexity:
- One check: O(number of digits) ≈ O(19)
- Overall: O(gap × 19), where 'gap' is the distance to the next fair number.
*/

bool isFair(int64 n) {
    int64 temp = n;
    int l = 1;

    while (temp > 0) {
        int d = temp % 10;
        temp /= 10;

        if (d != 0)
            l = lcm(l, d);
    }

    return (n % l == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int64 n;
        cin >> n;

        while (!isFair(n))
            n++;

        cout << n << '\n';
    }

    return 0;
}