#include<bits/stdc++.h>

using namespace std;

// For the Following Problem, the simple concept boils down to length of palindrome
// palindrom of even length should have no odd frequency letters, i.e all chars should
// have even frequency
// and palindrom of odd length should have only 1 char with odd frequency (to from the middle word)

int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;

        map<char,int> freq;

        for(int i = 0; i < n; i++){
            if(freq.find(str[i]) != freq.end()){
                freq[str[i]]++;
            }
            else{
                freq[str[i]] = 1;
            }
        }

        int len = n - k;
        int oddcounts = 0;
        for(auto it : freq){
            if(it.second % 2 != 0){
                oddcounts++;
            }
        }  
         

        // remove the odd counts
        if(k >= oddcounts){
            k -= oddcounts;

            if(len%2 == 0 && k%2 == 0){
                cout << "YES";
            }
            else if(len%2 != 0 && k%2 != 0){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
        }
        else{
           oddcounts -= k;
     
            if(len%2 == 0 && oddcounts == 0){
                cout << "YES";
            }
            else if(len%2 != 0 && oddcounts == 1){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
        }

        cout << "\n";

    }

}