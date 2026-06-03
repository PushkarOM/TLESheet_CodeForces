#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);
        
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        bool beautifull = false;
        
        // we need to find 2 number with gcd smaller that 2
        for(int i = 0; i < arr.size(); i++){
            for(int j = i+1; j < arr.size(); j++){
                if(gcd(arr[i],arr[j]) <= 2){
                    beautifull = true;
                    break;
                }
            }

            if(beautifull) break;
        }


        if(beautifull){
            cout << "YES";
        }
        else{
            cout << "NO";
        }   
        cout << "\n";

    }

}