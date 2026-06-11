#include<bits/stdc++.h>

using namespace std;

/*
For each character, the copies that survive must be the last
occurrences needed by the target string. Scan s from right to left,
keeping only the required number of occurrences of each character
(from frequencies in t). The kept characters are the unique possible
survivors. If they form t, answer YES; otherwise NO.
*/

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