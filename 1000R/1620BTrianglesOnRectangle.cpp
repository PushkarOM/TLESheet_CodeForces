#include<bits/stdc++.h>

using namespace std;

/*
Observation:
- For a fixed side, the maximum base is obtained by the first and last
  points since the coordinates are sorted.
- The third point should be chosen on the opposite parallel side to
  maximize the perpendicular height.
- Thus, for each of the four sides, the maximum doubled area is:
      (last - first) * (corresponding rectangle dimension)
- Compute this for all four sides and take the maximum.
*/

int main() {

    int t;
    cin >> t;

    while (t--) {
        long long w, h;
        cin >> w >> h;

        long long ans = 0;

        for (int side = 0; side < 4; side++) {
            int k;
            cin >> k;

            long long first, last;
            cin >> first;
            last = first;

            for (int i = 1; i < k; i++) {
                cin >> last;
            }

            long long base = last - first;

            if (side < 2) { // bottom or top
                ans = max(ans, base * h);
            } else { // left or right
                ans = max(ans, base * w);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}