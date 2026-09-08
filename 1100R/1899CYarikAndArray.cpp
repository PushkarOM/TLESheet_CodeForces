#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int t = 0;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        ll sum = arr[0];
        ll maxSum = LONG_MIN;
        for(int i = 1; i < n; i++){
            if(abs(arr[i]) % 2 != abs(arr[i-1]) % 2 ){
                if(sum < 0){
                    sum = 0;
                }  
                sum += arr[i];

            }
            else{
                sum = arr[i];
            }

            
            maxSum = max(sum, maxSum);

        }

        maxSum = max(sum, maxSum);
        cout << maxSum << "\n";
    }

}

