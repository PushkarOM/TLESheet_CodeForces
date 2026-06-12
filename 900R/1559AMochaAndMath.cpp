#include<bits/stdc++.h>

using namespace std;

// The final minimum possible maximum value is the bitwise AND of all elements.
// A bit that is 1 in every element can never be removed by any operation,
// while any other bit can be eliminated through repeated AND operations.
// Therefore, compute the AND of the entire array.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int val, temp;
        for(int i = 0; i < n; i++){
            if(i == 0){
                cin >> val;
                continue;
            }

            cin >> temp;
            val &= temp;
            
        }

        cout << val << '\n';

    }
}