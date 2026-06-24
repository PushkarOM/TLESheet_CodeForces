#include <bits/stdc++.h>
using namespace std;

/*
For every occurrence of color c, we need the time until the next green light.
Since the string is circular, duplicate it so that wrap-around becomes a normal
rightward traversal.

Scan the doubled string from right to left while maintaining the index of the
closest 'g' seen so far. For any position i, the waiting time to the next green
is simply (closest_g - i).

Among the original positions [0, n-1] whose character is c, take the maximum
waiting time because we do not know which occurrence of c we are currently at,
so we must consider the worst case.

Time: O(n) per test case
Space: O(1) extra (excluding the doubled string)
*/

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        char c;
        cin >> n >> c;

        string s;
        cin >> s;

        if (c == 'g') {
            cout << 0 << '\n';
            continue;
        }

        string doubled = s + s;

        int nearestG = -1;
        int ans = 0;

        for (int i = (int)doubled.size() - 1; i >= 0; --i) {
            if (doubled[i] == 'g')
                nearestG = i;

            if (i < n && doubled[i] == c)
                ans = max(ans, nearestG - i);
        }

        cout << ans << '\n';
    }

    return 0;
}