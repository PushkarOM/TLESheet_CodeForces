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
        ll maxSum = arr[0];
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

/*
We need the maximum-sum non-empty subarray with alternating parity.

The array can be viewed as alternating-parity segments:
- If adjacent elements have the same parity, the current valid subarray
  must break, so we start a new subarray from the current element.
- Otherwise, the current subarray can be extended.

Within a valid alternating segment, this becomes the normal Kadane's
algorithm:
- If the current sum is negative, discard it before adding the next element,
  since carrying a negative sum can only reduce any future subarray.
- Otherwise, keep extending the current subarray.

We maintain:
    sum    -> sum of the current valid subarray
    maxSum -> maximum valid subarray sum seen so far

Use abs(x) % 2 for the parity check because C++ gives negative remainders
for negative numbers.

Time:  O(n)
Space: O(n) for the input array, O(1) extra
*/
