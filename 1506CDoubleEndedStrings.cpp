#include <bits/stdc++.h>
using namespace std;


// Deleting characters only from the front or back means that the remaining
// part of a string must always be a substring of the original string.
//
// Therefore, after all operations, both strings must become the same
// common substring.
//
// If the chosen common substring has length k, then:
// - a needs |a| - k deletions
// - b needs |b| - k deletions
//
// Total operations = |a| + |b| - 2*k
//
// So we only need to find the longest common substring between a and b.
// Since |a| and |b| are at most 20, we can generate all substrings of a,
// check whether they occur in b using find(), and keep the maximum length.


int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, b;
        cin >> a >> b;

        int best = 0;

        for (int i = 0; i < a.size(); i++) {
            string cur = "";

            for (int j = i; j < a.size(); j++) {
                cur += a[j];

                if (b.find(cur) != string::npos) {
                    best = max(best, (int)cur.size());
                }
            }
        }

        cout << a.size() + b.size() - 2 * best << '\n';
    }

    return 0;
}
