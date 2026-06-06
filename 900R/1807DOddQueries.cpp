#include<bits/stdc++.h>

using namespace std;

// We only care whether the final sum is odd or even, not its actual value.
//
// Let parity(x) be 0 for even and 1 for odd.
// The new sum after a query is:
//
//     totalSum - rangeSum + k * length
//
// In parity arithmetic:
// - addition/subtraction become XOR
// - multiplication becomes AND
//
// So we store prefix parities instead of prefix sums.
// This lets us get the parity of any range in O(1),
// compute the parity of the updated total sum,
// and answer whether it is odd or even.
//
// Complexity: O(n) preprocessing + O(1) per query.

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, q, l, r, k;
        cin >> n >> q;
        
        vector<int> arr(n), pref(n);
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            
            // computing the prefix parity Array
            if(i == 0) pref[0] = (arr[0] % 2 == 0) ? 0 : 1;
            else pref[i] = ((pref[i-1] + arr[i]) % 2 == 0) ? 0 : 1;
        }
        
        while(q--){
            cin >> l >> r >> k;
            // converte to 0 based indexing
            l -= 1;
            r -= 1;
            
            int pK, plr, pfinal;
            pK = (k%2==0) ? 0 : 1;
            plr = ((r-l+1)%2==0) ? 0 : 1;
            
            if(l == 0){
                pfinal = pref[n-1] ^ pref[r] ^ (pK & plr);
            }
            else{
                pfinal = pref[n-1] ^ (pref[r] ^ pref[l-1]) ^ (pK & plr);
            }
            
            if(pfinal){
                cout <<"YES\n";
            }
            else{
                cout << "NO\n";
            }
                
        }
        
        
        
    }
}