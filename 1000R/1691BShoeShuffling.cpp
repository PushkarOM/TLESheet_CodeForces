#include<bits/stdc++.h>


using namespace std;
// Key Observation:
// Since the shoe sizes are sorted, shoes can never be exchanged between
// different shoe-size groups. A smaller shoe cannot satisfy a larger student,
// and moving a larger shoe into a smaller group would force a smaller shoe
// into the larger group, violating the size constraint. Therefore, each
// contiguous group of equal shoe sizes is completely independent.
//
// For every group:
//   - Size == 1 : impossible, as the only shoe available is their own.
//   - Size >= 2 : perform a cyclic left rotation of the indices so that
//                 everyone receives a different shoe of the same size.
//
// The last group is handled separately because the main loop terminates
// when r == n before processing it.

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> arr(n), result;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            result.push_back(i+1);
        }

        int l = 0, r = 0;
        bool flag = true;

        while(r < n){

            if(arr[l] == arr[r]){
                r++;
            }
            else{
                if(r - l == 1){
                    flag = false;
                    break;
                }
                else{
                    rotate(result.begin()+l, result.begin() + l + 1, result.begin()+r);
                    l = r;
                }
            }

        }

        if(flag){
            if (r - l == 1) {
                flag = false;
            } else {
                rotate(result.begin() + l,
                       result.begin() + l + 1,
                       result.begin() + r);
            }
        }
        
        if(flag){
            for(auto it : result){
                cout << it << " ";
            }
            cout << "\n";
        }
        else{
            cout << -1 << "\n";
        }

    }

}