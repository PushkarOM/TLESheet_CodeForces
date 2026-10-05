#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<ll> arr(n);
        ll countNeg = 0;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] < 0) countNeg++;
        }

        // if countNeg == odd, then 1 -ve number will remain after any number of ops
        // use the smallest number to be this number
        ll smallestABS = LLONG_MAX;
        ll sum_ = 0;
        for(auto it: arr){
            smallestABS = min(abs(it),smallestABS);
            sum_ += abs(it);
        }
        
        // cout << smallestABS << " ";

        if(countNeg % 2 == 0) cout << sum_ << '\n';
        else cout << (ll)(sum_ - 2 * smallestABS) << '\n';

    }

    return 0;    

}