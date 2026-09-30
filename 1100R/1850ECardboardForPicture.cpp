#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int t;
    cin >> t;

    while(t--){
        
        ll n, c, w;

        cin >> n >> c;

        vector<ll> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        ll low = 1, high = (ll)sqrt(c);

        while(low <= high){
            ll mid = low + (high - low) / 2;

            __int128 sum = 0;

            for(int i = 0; i < n; i++){
                __int128 x = arr[i] + 2 * mid;
                sum += x * x;
            }

            if(sum == c){
                w = mid;
                break;
            }
            else if(sum > c) high = mid-1;
            else low = mid+1;
        }

        cout << w << "\n";
    }

}