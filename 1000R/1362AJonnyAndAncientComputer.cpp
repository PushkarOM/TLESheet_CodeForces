#include <bits/stdc++.h>
using namespace std;

/*
APPROACH:

Allowed operations:
    *2, *4, *8
or
    /2, /4, /8

Observation:
1. One number must be an exact multiple of the other.
   Otherwise it is impossible.

2. Let ratio = larger / smaller.
   Example:
       1001 -> 1100611139403776
       ratio = 2^40

3. Since we can ONLY multiply/divide by powers of 2,
   ratio itself MUST be a power of 2.

   Efficient check:
       x is power of 2 iff
       x > 0 && (x & (x-1)) == 0

4. If ratio = 2^k,
   then we need to create exponent k using moves of:
        +3 (×8)
        +2 (×4)
        +1 (×2)

   Greedy is optimal:
       use as many 8s as possible,
       then 4s,
       then 2s.

Time Complexity : O(1)
*/

int main() {

    int t;
    cin >> t;

    while(t--){
        long long a, b;
        cin >> a >> b;

        // Already equal
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }

        long long ratio;

        if (a < b) {

            // Bigger must be divisible by smaller
            if (b % a != 0) {
                cout << -1 << "\n";
                continue;
            }

            ratio = b / a;
        }
        else {

            // Same idea for division
            if (a % b != 0) {
                cout << -1 << "\n";
                continue;
            }

            ratio = a / b;
        }

        // Check if ratio is a power of 2.
        //
        // Example:
        // 16 = 10000
        // 15 = 01111
        //
        // 10000 & 01111 = 00000
        //
        // This only happens for powers of two.
        if ((ratio & (ratio - 1)) != 0) {
            cout << -1 << "\n";
            continue;
        }

        /*
            __builtin_clzll(x)
                = Count Leading Zeros (64-bit integer)

            Example:

            ratio = 16

            Binary:
            000....00010000

            Leading zeros = 59

            Highest set bit =
            63 - 59 = 4

            Therefore:
            16 = 2^4

            So exponent = 4.
        */
        int exponent = 63 - __builtin_clzll(ratio); 

        int ans = 0;

        // Use as many *8 (or /8) operations as possible.
        ans += exponent / 3;
        exponent %= 3;

        // Then *4 (or /4).
        ans += exponent / 2;
        exponent %= 2;

        // Remaining exponent becomes *2 (or /2).
        ans += exponent;

        cout << ans << "\n";
    }

    return 0;
}
