#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main(){
    
    int t;
    cin >>  t;

    while(t--){

        ll n, x;
        cin >> n >> x;

        vector<ll> arr(n);
        for(int i=0; i < n; i++){
            cin >> arr[i];
        }

        ll low = 1;
        // upper bound for walls is 
        // total water required and the max height of a wall
        ll high = *max_element(arr.begin(), arr.end()) + x; 
        

        // we basically need to apply bninary seach on the height high and low, 
        // and find a appropriate value for height that give us water x

        while(low <= high){
            ll mid = low + (high - low) / 2;

            ll water = 0;

            for(ll height : arr){
                if (height < mid)
                    water += mid - height;
            }

            if (water <= x) {
                low = mid + 1;       // mid works, try bigger
            } else {
                high = mid - 1;       // mid doesn't work
            }
        }

        cout << high << "\n";

    }

}

 /*
            Approach: Binary Search on the answer (tank height h)

            For any chosen height h, the amount of water required is:

                water = sum(max(0, h - arr[i]))

            If arr[i] >= h, that coral column is already tall enough,
            so we don't need to add any water.

            This gives us a monotonic condition:

                If height h is feasible (water <= x),
                then every height smaller than h is also feasible.

                If height h is NOT feasible (water > x),
                then every height larger than h is also not feasible.

            Therefore, we can binary search for the largest feasible h.

            low  = smallest possible height = 1
            high = max(arr) + x

            Why max(arr) + x?
            Even if we raise the tank above the tallest coral, going
            more than x units above max(arr) would require more than
            x units of water just for that tallest column.

            For each mid:
                1. Calculate the water needed to make every column
                   reach height mid.
                2. If water <= x:
                       mid is feasible -> search higher.
                   Otherwise:
                       mid is impossible -> search lower.

            When the binary search ends, high is the largest
            feasible height.

            Time Complexity:  O(n log(max(arr) + x))
            Space Complexity: O(n)
        */

        