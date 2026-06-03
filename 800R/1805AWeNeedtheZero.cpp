#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n, x = 0;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            x ^= arr[i];
        }
        
        int check = 0;
        for(auto it : arr){
            check ^= x^it;
        }

        if(!check){
            cout << x;
        }
        else{
            cout << -1;
        }
        cout << "\n";


        
    }

}