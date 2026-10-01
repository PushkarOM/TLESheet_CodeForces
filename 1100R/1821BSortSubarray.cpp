#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<ll> a(n), b(n);

        for(auto &x : a) cin >> x;
        for(auto &x : b) cin >> x;
        

        int left = 0, right = n-1;
        bool stop = false;
        
        while(true){
            
            if(a[left] != b[left]) break;
            left++;
        
        }

        while(true){
   
            if(a[right] != b[right]) break;
            right--;
        }
        

        // moving out wards in b to find the max possible size subarray
        
        while(left > 0 && b[left] >= b[left-1]){
            left--;
        }

        while(right < n-1 && b[right] <= b[right+1]){
            right++;
        }
        
        cout << left+1 << " " << right+1 << '\n';

    }

    return 0;
}


// First find the smallest subarray that must have been sorted:
// the first and last positions where a[i] != b[i].
//
// Since b is the result after sorting that subarray, b[left..right]
// must be non-descending. We can therefore expand the segment outward
// while the sorted order of b is still maintained.
//
// Expand left while:
//     b[left - 1] <= b[left]
//
// Expand right while:
//     b[right] <= b[right + 1]
//
// Each pointer moves at most n positions, so the total complexity is O(n).
