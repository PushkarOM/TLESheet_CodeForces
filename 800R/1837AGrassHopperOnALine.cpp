#include<bits/stdc++.h>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int x, k, temp;

        cin >> x >> k;
        temp = x;

        vector<int> arr;
        while(x > 0){
            if(temp%k == 0) temp--;
            else{
                x -= temp;
                arr.push_back(temp);
                temp = x;
            }
        }

        cout << arr.size() << "\n";
        for(auto it: arr){
            cout << it << " ";
        }
        cout << "\n";
    }

}