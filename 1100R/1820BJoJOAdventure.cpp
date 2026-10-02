#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        long long n = s.size();

        // If every character is 1, the entire n x n matrix is valid.
        if (count(s.begin(), s.end(), '1') == n) {
            cout << n * n << '\n';
            continue;
        }

        long long consecutiveOnes = 0;
        long long longestRun = 0;

        for (int i = 0; i < 2 * n; i++) {
            if (s[i % n] == '1') {
                consecutiveOnes++;

                // A circular run cannot be longer than the original string.
                consecutiveOnes = min(consecutiveOnes, n);

                longestRun = max(longestRun, consecutiveOnes);
            } else {
                consecutiveOnes = 0;
            }
        }

        long long height = (longestRun + 1) / 2;
        long long width = (longestRun + 2) / 2;

        cout << (long long)height * width << '\n';
    }
}

// The matrix looks like a huge grid problem, but we never need to build it.
//
// Every row is a cyclic shift of the original string. Because of this,
// a rectangle of 1s can be represented using consecutive 1s in the
// original string, treating it as circular.
//
// Suppose a rectangle has:
//      height = h
//      width  = w
//
// Because each row is shifted by 1 position, an h x w rectangle covers
// only (h + w - 1) consecutive positions of the original circular string.
//
// Example for a 2 x 3 rectangle:
//
//      1 1 1
//        1 1 1
//
// The required positions in the original string are only:
//
//      1 1 1 1
//
// Therefore, if the longest circular run of 1s is k:
//
//      h + w - 1 <= k
//      h + w <= k + 1
//
// To maximize the rectangle area h * w, we use the full available sum:
//
//      h + w = k + 1
//
// Now comes the mathematical observation:
// For two positive numbers with a fixed sum S, their product is maximum
// when they are as close to each other as possible.
//
// Why?
//
//      w = S - h
//
// So:
//
//      h * w = h * (S - h)
//            = S*h - h^2
//
// This is a downward-opening quadratic, whose maximum occurs at h = S/2.
// Therefore, h and w should be equal if possible, otherwise they should
// be the two closest integers.
//
// Here S = k + 1, so:
//
//      h = (k + 1) / 2
//      w = (k + 2) / 2
//
// We find k by traversing the string twice using i % n, which simulates
// the circular string without actually constructing s + s.
//
// The run is capped at n because the matrix is only n x n.
//
// Time:  O(n) per test case
// Space: O(1)
