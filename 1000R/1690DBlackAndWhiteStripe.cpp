#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, k;

        cin >> n >> k;
        
        string str;
        cin >> str;

        int whiteFreq = 0;

        int i = 0;
        while(i < k){
            if(str[i] == 'W') whiteFreq++;
            i++;
        }
        
        int minCost = INT_MAX;
        while(i < str.length()){

            if(whiteFreq < minCost) minCost = whiteFreq;

            if(str[i-k] == 'W') whiteFreq--;
            if(str[i] == 'W') whiteFreq++;
            i++;
            
        }

        if(i == str.length()) minCost = min(minCost, whiteFreq);

        cout << minCost << "\n";
    }

}