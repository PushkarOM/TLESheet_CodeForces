#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(x) (x).begin(), (x).end()

// global precmpute array
vector<int> pairs[1001];

void solve() {
    int n;
    cin >> n;

    vector<int> idx(1001,0);

    // start with storing the ocurence of the number, overwrite same number occurence with it's later ones 
    for(int i = 1 ; i <= n; i++){
        int temp;
        cin >> temp;
        idx[temp] = i;
    }

    int ans = -1;
    
    
    for(int i = 1; i <= 1000; i++){
        // if a number exsist, check for it's coprime else continue
        if(idx[i] == 0) continue;

        for(int j : pairs[i]){
            
            if(idx[j] != 0){
                ans = max(ans, idx[i] + idx[j]); // if a coprime found with that number that also exsist int the given array, compare and update ans
            }

        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // precompute coprime for each value till 1000
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            if(__gcd(i,j) == 1) pairs[i].push_back(j);
        }
    }


    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
