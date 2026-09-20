#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n,k,a,b;
        cin >> n >> k >> a >> b;
        
        // 0 base index
        a -= 1;
        b -= 1;
        
        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i].first >> arr[i].second;
        }


        ll direct = llabs((ll)arr[a].first - arr[b].first) + llabs((ll)arr[a].second - arr[b].second);
        ll fromA = LLONG_MAX;
        ll fromB = LLONG_MAX;

        // if no major cities
        if (k == 0) {
            cout << direct << '\n';
            continue;
        }


        for(int i = 0; i < k; i++){

            // distance of a from current major citiy
            ll dist = llabs((ll)arr[a].first - arr[i].first) + llabs((ll)arr[a].second - arr[i].second);
            fromA = min(fromA, dist);

            // distance of b from every major city
            dist = llabs((ll)arr[b].first - arr[i].first) + llabs((ll)arr[b].second - arr[i].second);
            fromB = min(fromB, dist);
            
        }


        cout << min(direct, fromA + fromB) << '\n';


    }
}