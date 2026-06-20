#include<bits/stdc++.h>

using namespace std;

// first we need to find valids lens of subequneces, valid meaning len >= k
// then we need to find consecutive subsets of len >= k
// Formula  : ((n - k + 1) * (n - k + 2)) / 2 , n is the len of subsequence

int main(){

    long long t;
    cin >> t;

    while(t--){
        
        long long n, k , q;
        cin >> n >> k >> q;

        vector<long long> arr(n);
        
        for(long long i = 0; i < n; i++){
            cin >> arr[i];
        }

        long long len = 0, sum = 0;

        for(auto it : arr){
            if(it <= q){
                len++;

            }
            else{

                if(len >= k)
                    sum += ((len - k + 1) * (len - k + 2)) / 2;
                
                len = 0;
            }

        }

        if(len >= k)
            sum += ((len - k + 1) * (len - k + 2)) / 2;
        
       

        cout << sum << "\n";
    }

}