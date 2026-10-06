#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        long long total = 0;

        for (auto &x : a) {
            cin >> x;
            total += x;
        }

        // Find divisors of the total sum.
        vector<long long> divisors;

        for (long long d = 1; d * d <= total; d++) {
            if (total % d == 0) {
                divisors.push_back(d);

                if (d != total / d)
                    divisors.push_back(total / d);
            }
        }

        // Try larger possible GCDs first.
        sort(divisors.rbegin(), divisors.rend());

        for (long long g : divisors) {
            long long current = 0;
            int segments = 0;

            for (long long x : a) {
                current += x;

                if (current % g == 0) {
                    segments++;
                    current = 0;
                }
            }

            // Need at least 2 segments.
            if (segments >= 2) {
                cout << g << '\n';
                break;
            }
        }
    }

    return 0;
}

/*
    GCD Partition

    Key observation:
    -----------------
    Suppose the array is split into segments with sums:

        s1, s2, s3, ..., sk

    and their GCD is g.

    Since g divides every segment sum, it must also divide their total:

        g | s1
        g | s2
        ...
        g | sk

        => g | (s1 + s2 + ... + sk)
        => g | total_array_sum

    Therefore, the answer MUST be a divisor of the total array sum.
    We only need to try those candidates.

    Checking a candidate g:
    ------------------------
    We greedily build segments using a running sum.

        current += a[i]

    Whenever current % g == 0, we can end the current segment.

    Why is this safe?
    All array elements are positive, so once the running sum becomes
    divisible by g, cutting there gives us a valid segment and cannot
    hurt our ability to form the remaining segments.

    We need at least 2 segments because k >= 2.

    We try divisors from largest to smallest.
    Therefore, the first candidate that allows a valid partition is
    the maximum possible score.

    Example:
        a = [1, 2, 1, 1, 1, 3]
        total = 9
        divisors = 9, 3, 1

        g = 9:
            [1,2,1,1,1,3] -> one segment
            invalid because k >= 2

        g = 3:
            [1,2] [1,1,1] [3]
              3       3      3

            gcd(3,3,3) = 3
            valid -> answer = 3

    Complexity:
        Finding divisors: O(sqrt(total))
        Checking candidates: O(n * number_of_divisors)

        Usually the number of divisors is small enough for the constraints.
*/