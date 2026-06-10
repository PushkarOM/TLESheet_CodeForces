#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<long long> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        int count_ = 0;

        // traverse right to left
        for(int i = n - 1; i > 0; i--){

            while(arr[i] <= arr[i-1] && arr[i-1] != 0){

                arr[i-1] /= 2;
                count_++;
            }
        }

        
        bool complete = true;

        for(int i = 0; i < n-1; i++){
            if(arr[i] >= arr[i+1]){
                complete = false;
                break;
            }
        }

        if(complete) cout << count_ << "\n";
        else cout << -1 << "\n";
    }
}