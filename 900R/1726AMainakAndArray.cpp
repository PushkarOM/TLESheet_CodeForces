#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, prefixDiff = 0, suffixDiff = 0, cyclicPairs = 0;
        cin >> n;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        // prefix family
        prefixDiff = arr[n-1] - *min_element(arr.begin(),arr.end());
        
        // suffix family
        suffixDiff = *max_element(arr.begin(),arr.end()) - arr[0];
        
        // to form cyclic pairs
        int current = 0;
        for(int i = 0; i < n-1; i++){
            
                current = arr[i] - arr[i+1];
                if(current > cyclicPairs){
                    cyclicPairs = current;
                }
        }
        
        if(arr[n-1] - arr[0] > cyclicPairs){
            cyclicPairs = arr[n-1] - arr[0];
        }
        
        
        cout <<  max(max(prefixDiff,suffixDiff),cyclicPairs) << "\n";
    }
}