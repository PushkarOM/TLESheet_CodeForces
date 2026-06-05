#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        long long n,k, len = 0, curr_len = 1;
        cin >> n >> k;
        
        vector<long long> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
        
        sort(arr.begin(), arr.end());
        
        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i-1] <= k)
                curr_len++;
            else
                curr_len = 1;
        
            len = max(len, curr_len);
        }
        
        cout << n - len <<"\n";
        
        
    }
    
}