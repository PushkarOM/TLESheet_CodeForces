#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
    
        int n;
        cin >> n;

        vector<int> arr(n), frontTwo(n);
        int count = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] == 2) count++;
        }

        if(count%2 != 0){
            cout << -1 << "\n";
            continue;
        }

        if(arr[0] == 2) frontTwo[0]++;

        for(int i = 1; i < n; i++){
            if(arr[i] == 2){
                frontTwo[i] += 1 + frontTwo[i-1];
            }
            else{
                frontTwo[i] = frontTwo[i-1];
            }
        }

        int k;
        for(int i = 0; i < n; i++){
            if(frontTwo[i] == count/2){
                k = i+1;
                break;
            }
        }

        cout << k << '\n';
    }

}