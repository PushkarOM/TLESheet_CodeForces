#include<bits/stdc++.h>

using namespace std;
/*
Key Observation:

If we apply an operation on a segment, every element in that segment
becomes the XOR of the entire segment.

For an even-length segment:
[x, x, x, ..., x] (even count)
the XOR of all elements is 0.

Therefore, applying the same operation twice on an even-length segment
turns the whole segment into zeros.

Construction:

1. If n is even:
   - Apply the operation on the whole array twice.
   - After the first operation, all elements become equal.
   - Since the array length is even, the second operation makes
     every element 0.

2. If n is odd:
   - Apply the operation on the whole array once.
     -> Array becomes [x, x, ..., x]
   - Apply the operation on the first n-1 elements.
     -> Since n-1 is even, they become 0
     -> Array becomes [0, 0, ..., 0, x]
   - Apply the operation on the last two elements twice.
     -> First time: [0, x] becomes [x, x]
     -> Second time: [x, x] becomes [0, 0]

This uses only 2 operations for even n and 4 operations for odd n,
which is well within the limit of 8.
*/

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }

        if(n%2 == 0){
            cout << 2 << "\n" << 1 << " " << n << "\n" << 1 << " " << n << "\n";
        }
        else{
            cout << 4 << "\n";
            cout << 1 << " " << n-1 << "\n";
            cout << 1 << " " << n-1 << "\n";
            cout << n - 1 << " " << n << "\n"; 
            cout << n - 1 << " " << n << "\n";
        }
    }

}