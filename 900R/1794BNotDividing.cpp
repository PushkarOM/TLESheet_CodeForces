#include<bits/stdc++.h>

using namespace std;
// Any positive number is divisible by 1, so first convert all 1s to 2.
//
// Then scan left-to-right. If a[i+1] is divisible by a[i],
// increment a[i+1] once. Since a[i] > 1, after incrementing:
//
//     (a[i+1] + 1) % a[i] = 1
//
// so the current pair immediately becomes valid.
//
// We only modify the right element of a bad pair, which cannot
// affect any previously fixed pair. Each element is incremented
// at most once for being 1 and at most once while fixing a pair,
// keeping the total operations within the allowed 2n.
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<long long> arr(n);
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        // check for 1s
        for(int i = 0; i< n; i++){
            if(arr[i] == 1) arr[i]++;
        }
        
        // check for bad pairs
        for(int i = 0; i < n-1; i++){
            if(arr[i+1]%arr[i] == 0){
               arr[i+1]++;
            }
        }
        
        for(auto it : arr){
            cout << it << " ";
        }
        cout << "\n";
    }
    
}