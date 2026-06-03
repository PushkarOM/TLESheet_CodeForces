#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        // 1 to n 
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int sum =  n + 1;
        for(int i = 0; i < n; i++){
           b[i] = sum - a[i];
        }

        for(int i = 0 ; i < n; i++){
            cout << b[i] << " ";
        }
        cout << "\n";
    }

}