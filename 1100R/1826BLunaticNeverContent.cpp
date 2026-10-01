#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<ll> a(n);

        for(auto &x : a) cin >> x;

        ll ans = 0;

        for(int i = 0; i < n/2; i++){

            ll diff = llabs((ll)a[i] - a[n-1-i]);
            ans = gcd(ans, diff);

        }

        cout << ans << "\n";

    }

}


// For the array after taking modulo k to be a palindrome,
// every mirrored pair must have the same remainder:
//
//     a[i] % k == a[n-1-i] % k
//
// This is true exactly when k divides their difference:
//
//     k | (a[i] - a[n-1-i])
//
// Therefore, k must divide the difference of every mirrored pair.
// The largest such k is the GCD of all these absolute differences.
//
// Initialize ans = 0 since gcd(0, x) = x.
// If all differences are 0, ans remains 0, meaning the array
// is already a palindrome and any k works.

