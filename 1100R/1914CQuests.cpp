#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
We maintain a running prefix sum of `a` up to `min(n, k)`.
If we decide to stop after reaching quest `i`, all quests `1...i` 
have been completed once, giving us the prefix sum.
Since all quests `1...i` are now available for repeated completion, 
we choose the quest with the maximum `b` value and repeat it for the 
remaining `k - i` moves.
We calculate the score for every possible stopping point `i` and 
maintain the maximum score encountered.
*/

int main(){

    int t = 0;
    cin >> t;
    
    while(t--){

        int n , k;
        cin >> n >> k;


        vector<ll> a(n), b(n);
        for(int i = 0; i <n; i++){
            cin >> a[i];
        }

        for(int i = 0; i <n; i++){
            cin >> b[i];
        }

        ll prefix = 0, maxB = b[0], score = 0, ans = 0;

        for(int i  = 0; i < min(k,n); i++){
            prefix += a[i];
            maxB = max(maxB, b[i]);

            score = prefix + (k-i-1) * maxB;
            ans = max(ans, score);
        }
        
        cout << ans << "\n";

    }

}