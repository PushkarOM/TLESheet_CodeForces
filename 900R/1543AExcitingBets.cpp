#include<bits/stdc++.h>

using namespace std;

// Difference between a and b remains invariant after every move.
// Therefore the maximum possible GCD must divide |a-b|, so the largest possible
// excitement is |a-b| itself (except when a == b, where excitement is infinite).
// To make both numbers multiples of d = |a-b|, compute r = a % d.
// We can either move down by r or up by d-r, so the minimum moves are min(r, d-r).

int main(){

    int t;
    cin >> t;

    while(t--){

        long long a, b;
        cin >> a >> b;
        
        long long diff = abs(a-b);
        long long r = 0;

        if(diff != 0) r = a%diff;

        cout << diff << " " << min(r, diff-r) << "\n";

    }

}