#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {
        long long n, m, i, j;
        cin >> n >> m >> i >> j;

        cout << 1 << " " << 1 << " "
             << n << " " << m << '\n';
    }

    return 0;
}

// The required path is:
// Start -> YoYo1 -> YoYo2 -> Start
//
// Since Manhattan distance is symmetric, the order of visiting the two yo-yos
// does not matter, giving the total distance:
// dist(S, A) + dist(S, B) + dist(A, B)
//
// Splitting Manhattan distance into row and column components reduces the
// problem into two independent 1D optimizations:
//
// |a - s| + |b - s| + |a - b|
//
// Considering the relative positions of a, b, and s:
// 1) a <= b <= s  : value = 2(s - a)      -> maximize by taking a = 1
// 2) s <= a <= b  : value = 2(b - s)      -> maximize by taking b = n
// 3) a <= s <= b  : value = 2(b - a)      -> maximize by taking a = 1, b = n
//
// The third case always gives the largest possible distance, meaning the two
// chosen positions in one dimension must be the two endpoints of the interval.
//
// Hence, for rows we take 1 and n, and for columns we take 1 and m.
// Combining these extremes gives any pair of opposite corners of the grid
// (e.g., (1,1) and (n,m)), which always maximizes Anton's travel distance.
