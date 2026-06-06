#include<bits/stdc++.h>

using namespace std;

/*
Let pos[x] be the current position of value x.

If we choose a fixed k, every swap moves a value by exactly k positions,
so a value can only stay within its modulo-k residue class.

Therefore, for value x to reach its target position x, we must have:
    k | (pos[x] - x)
for every x.

Hence any valid k must divide all displacements (pos[x] - x).

Conversely, if k divides every (pos[x] - x), then each value already
lies in the same modulo-k group as its destination. Positions with the
same remainder modulo k form independent chains, and adjacent swaps
along a chain can realize any permutation within that chain.

Thus the maximum valid k is:
    gcd(|pos[x] - x|) for all x.
*/

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int> permu(n+1), pos(n+1);
        
        for(int i = 0; i < n; i++){
            cin >> permu[i];
        }
        
        for(int i = 0; i < n; i++){
            pos[permu[i]] = i+1;
        }
        
        // gcd
        int gcdVal = 0;
        for (int x = 1; x <= n; x++) {
            gcdVal = gcd(gcdVal, abs(pos[x] - x));
        }
                
        cout << gcdVal << "\n";
        
    }
}