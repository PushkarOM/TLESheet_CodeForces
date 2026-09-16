#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

// For every divisor k of n, divide the array into consecutive groups of k boxes.
// Use prefix sums to calculate each group's weight in O(1), then find the
// maximum and minimum group weights. Update the answer with their difference.
// We only iterate up to sqrt(n); whenever i divides n, both i and n/i are
// valid group sizes, giving all possible k values efficiently.

int main (){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<ll> arr(n), prefixSum(n+1);
        prefixSum[0] = 0;
        ll maxDiff = LONG_LONG_MIN;

        for(int i = 0; i < n; i++){
           
            cin >> arr[i];
            prefixSum[i + 1] = prefixSum[i] + arr[i];
        }

        for(int i = 1; i * i <= n; i++){
            if(n%i != 0) continue;

            // i is a potential value
            ll maxSum = LONG_LONG_MIN, minSum = LONG_LONG_MAX;
            for(int j = 0; j < n; j += i){
                ll sum = prefixSum[j+i] - prefixSum[j];
                maxSum = max(sum, maxSum);
                minSum = min(sum, minSum);
            }

            maxDiff = max(abs(maxSum - minSum), maxDiff);

            // n/i is also a potential value
            if(i != n/i){
                maxSum = LONG_LONG_MIN;
                minSum = LONG_LONG_MAX;
                for(int j = 0; j < n; j += n/i){
                    ll sum = prefixSum[j+n/i] - prefixSum[j];
                    maxSum = max(sum, maxSum);
                    minSum = min(sum, minSum);
                }
            }

            maxDiff = max(abs(maxSum - minSum), maxDiff);
            
        }

        cout << maxDiff << "\n";

    }

}