#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    
    while(t--){
        int n, t;
        cin >> n;

        vector<int> arr;
        bool flag = true;

        for(int i = 0 ; i < n; i++){
            cin >> t;
            arr.push_back(t);
            if(i >= 1 && arr[i] < arr[i-1]) flag = false;
        }

        if(!flag){
            cout << 0 << "\n";
            continue;
        }

        // min difference
        int diff = INT_MAX;

        for(int i = 1; i < n; i++){
            if(arr[i] - arr[i-1] < diff){
                diff = arr[i] - arr[i-1];
            }
        }
        diff /= 2;
        cout << diff + 1 << "\n";
    }

}