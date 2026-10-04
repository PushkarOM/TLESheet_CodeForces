#include<bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> a(n, vector<int>(n));

        for (auto &row : a)
            for (int &x : row)
                cin >> x;

        int mismatch = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != a[n - 1 - i][n - 1 - j])
                    mismatch++;
            }
        }

        int needed = mismatch / 2;

        if (k < needed) {
            cout << "NO\n";
        }
        else if (n % 2 == 0 && (k - needed) % 2 != 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}

