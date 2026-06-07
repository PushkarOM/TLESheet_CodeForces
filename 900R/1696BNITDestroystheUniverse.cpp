#include<bits/stdc++.h>

using namespace std;

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
        
        // all no zero segements in the array
        int count_ = 0;
        bool set = false;
        for(int i = 0; i < n; i++){
            if(arr[i] != 0 && !set){
                set = true;
                count_++;
            }
            else if(arr[i] == 0 && set){
                set = false;
            }
         
            if(count_ > 1){
                count_ = 2;
                break;
            }   
        }
        
        cout << count_ << "\n";
    }
}