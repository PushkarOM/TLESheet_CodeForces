#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        string word, target;
        cin >> word >> target;
        
        vector<int> freq(26,0);
        for (char c : target) {
            freq[c - 'A']++;
        }
        
        
        string formed;
        for(int i = word.size() - 1; i >= 0; i--){
            int idx = word[i] - 'A';

            if (freq[idx] > 0) {
                formed.push_back(word[i]);
                freq[idx]--;
            }
        }
        
        reverse(formed.begin(), formed.end());
        
        if(formed == target) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    
}