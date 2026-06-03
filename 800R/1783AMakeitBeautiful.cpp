#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0 ; i < n; i++){
            cin >> arr[i];
        }

        // vector<int> prefixSum(n);
        // prefixSum[0] = 0;

        // for(int i = 1 ; i < n; i++){
        //     prefixSum.push_back(prefixSum[i]+arr[i-1]);
        // }



        bool flag = false;
        int first = arr[0];
        for(int i = 1; i < n; i++){
            if(first != arr[i]){
                flag = true;
                break;
            }
        }

        if(flag){
            cout << "YES\n";
            int sum  = arr[0];
            for(int i = 1; i < n; i++){
                if(sum == arr[i]){
                    sum -= arr[0];
                    sum += arr[n-1];
                    swap(arr[0],arr[n-1]);
                }
                sum += arr[i];
            }
            for(auto it : arr){
                cout << it << " ";
            }
            cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }

}