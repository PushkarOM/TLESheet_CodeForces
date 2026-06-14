#include<bits/stdc++.h>

using namespace std;

// Start by observing small cases:
// 2, 4, 8, 16 have no odd divisors > 1, and all are powers of 2.
//
// Any number can be written as n = 2^k * m, where m is odd.
// A direct approach is to repeatedly divide (or right shift) by 2
// until we remove all factors of 2 and reach the remaining odd part m.
// If m = 1, n is a pure power of 2 and has no odd divisor > 1.
// If m > 1, m itself is an odd divisor of n, so the answer is YES.
//
// Instead of repeatedly removing factors of 2 (O(log n)), we can
// detect powers of 2 more efficiently using their binary property:
// powers of 2 contain exactly one set bit. n & (n - 1) removes the
// rightmost set bit:
// - result == 0 : only one set bit -> power of 2 -> NO
// - result != 0 : multiple set bits -> not a power of 2 -> YES

int main(){

    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        if(!(n & (n-1))) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }

}

