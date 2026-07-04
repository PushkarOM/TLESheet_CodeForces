#include<bits/stdc++.h>

using namespace std;

// for a give r and b, where b < r. we want to construct a string with least consicutive r
// this can also be though as, dividing r len string made of "R"
//  into b+1 segments using "B" as a char between them.
// so max len of a "R" segment will be  
// base len -> r / (b+1)
// and extra required for each group (due to remainder) r % (b+1)
// so out of n base len group, extra number of gropu get an addtional "R"

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, r, b;
        cin >> n >> r >> b;

        int base = r / (b + 1);
        int extra = r % (b + 1);

        string ans = "";

        for (int i = 0; i <= b; i++) {
            // Every segment gets 'base' R's
            for (int j = 0; j < base; j++)
                ans += 'R';

            // The first 'extra' segments get one additional R
            if (extra > 0) {
                ans += 'R';
                extra--;
            }

            // Place a B after every segment except the last
            if (i != b)
                ans += 'B';
        }

        cout << ans << "\n";

    }
}