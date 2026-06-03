#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        long long int n, k;
        cin >> n >> k;
       
        if((n%2 != 0 && k%2 == 0)){
            cout << "NO";
        }
        else{
            cout << "YES";
        }
        cout << "\n";


    }

}