#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int &x : a)
            cin >> x;

        // Sort in descending order.
        // Then for i < j:
        // j - i > 0, while a[j] - a[i] <= 0,
        // so the two can never be equal.
        sort(a.begin(), a.end(), greater<int>());

        for (int x : a)
            cout << x << " ";

        cout << '\n';
    }

    return 0;
}
