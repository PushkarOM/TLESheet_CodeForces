#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<long long> smallest(n,INT_MAX);
        vector<long long> secondSmallest(n,INT_MAX);
        

        for(int i = 0; i < n; i++){
            int m;
            cin >> m;
            vector<int> dummy(m);

            for(int j = 0; j < m; j++){
                cin >> dummy[j];
            }

            // sort 
            sort(dummy.begin(), dummy.end());
            smallest[i] = dummy[0];
            secondSmallest[i] = dummy[1];

            
        }

        // smallest in the second smallest
        long long sm = INT_MAX, sum_2min = 0;
        for(int i = 0; i < n; i++){
            if(secondSmallest[i] < sm){
                sm = secondSmallest[i];
            }

            sum_2min += secondSmallest[i];
        }
        
        sum_2min -= sm;

        sm = INT_MAX;
        for(int i = 0; i < n; i++){
            if(smallest[i] < sm){
                sm = smallest[i];
            }
        }

        cout << sum_2min + sm << "\n";
    }


}