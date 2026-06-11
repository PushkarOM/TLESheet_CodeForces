#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        
        map<int,int> freq;
        int maxFreq = 0, index;
        
        for(int i = 0 ; i < n; i++){
            freq[arr[i]]++;
            if(freq[arr[i]] > maxFreq){
                maxFreq = freq[arr[i]];
                index = i;
            }
        }
        
        int lenReplace = n - maxFreq;
        int cost = 0;
        while(lenReplace){
            cost += 1; // to dupe the array
            
            if(lenReplace - maxFreq > 0){
                cost += maxFreq; // to copy the elements
                lenReplace -= maxFreq;
                maxFreq *= 2;
            }
            else{
                cost += lenReplace;
                lenReplace = 0;
            }
                
        }
        
        cout << cost << "\n";
    }
    
}