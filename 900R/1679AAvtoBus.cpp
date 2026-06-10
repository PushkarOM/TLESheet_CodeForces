#include<bits/stdc++.h>

using namespace std;


int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        long long n;
        cin >> n;
        
        if(n < 4 || n % 2 != 0){
            cout << -1 << "\n";
            continue;
        }
        
        long long maxBus, minBus;
        
        maxBus = n/4;
        minBus = n%6 == 0 ? n/6 : (n/6) + 1;
        
        cout << minBus << " " << maxBus  << "\n";
        
    }
    
}