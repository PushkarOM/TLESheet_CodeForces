#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x;

        
        long long minBeauty = 0, maxBeauty = 0;
        long long temp;
        for(int i = 0; i < n; i++){
            cin >> temp;
            minBeauty += temp;
            maxBeauty += (temp + x - 1) / x;
        }

        minBeauty = (minBeauty + x - 1) / x;

        
        cout << minBeauty << " " << maxBeauty << "\n";
    }

}