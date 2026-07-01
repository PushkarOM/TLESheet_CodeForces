#include <bits/stdc++.h>
using namespace std;

// Maintain the interval of all affinity values that can be kept unchanged
// since the last modification. For each pile, intersect the current interval
// with the pile's valid interval [a[i]-x, a[i]+x]. If the intersection is
// empty, a change is forced before this pile, so increment the answer and
// restart the interval with the current pile's interval.

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long L = a[0] - x;
        long long R = a[0] + x;

        int changes = 0;

        for (int i = 1; i < n; i++) {
            long long l = a[i] - x;
            long long r = a[i] + x;

            long long newL = max(L, l);
            long long newR = min(R, r);

            if (newL <= newR) {
                // Keep the same affinity
                L = newL;
                R = newR;
            } else {
                // Change affinity before this pile
                changes++;
                L = l;
                R = r;
            }
        }

        cout << changes << '\n';
    }

    return 0;
}
