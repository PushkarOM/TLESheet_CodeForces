#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        vector<int> runA(2 * n + 1, 0);
        vector<int> runB(2 * n + 1, 0);

        // longest runs in a
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;

            runA[a[i]] = max(runA[a[i]], j - i);
            i = j;
        }

        // longest runs in b
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && b[j] == b[i]) j++;

            runB[b[i]] = max(runB[b[i]], j - i);
            i = j;
        }

        int ans = 0;

        for (int v = 1; v <= 2 * n; v++) {
            ans = max(ans, runA[v] + runB[v]);
        }

        cout << ans << '\n';

    }

}