#include<bits/stdc++.h>

using namespace std;

// O(1) solution

int main(){

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        int neg = 0, pos = 0;

        for(int i = 0; i < n; i++){
            cin >> arr[i];

            if(arr[i] == 1) pos++;
            else neg++;
        }

        if(pos >= neg){
            if(neg%2 == 0){
                cout << 0 << "\n";
            }
            else{
                cout << 1 << "\n";
            }
        }
        else{
            int diff = neg - pos;
            
            if(diff%2 != 0) diff+=1;
            diff /= 2;

            neg -= diff;
            pos += diff;

            if(neg%2 == 0){
                cout << diff << '\n';
            }   
            else{
                cout << diff+1 << "\n";
            }
        }

    }

}