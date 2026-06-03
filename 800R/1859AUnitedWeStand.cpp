#include<bits/stdc++.h>

using namespace std;

int main(){


    int t;
    cin >> t;

    while(t--){
        int a, t;
        cin >> a;

        vector<int> arr, arrA, arrB;
        bool flag = true;

        for(int i = 0; i < a; i++){
            cin >> t;
            arr.push_back(t);
            if(i >= 1 && arr[i] != arr[i-1]) flag = false;
        }

        if(flag){
            cout << -1 << "\n";
            continue;
        }

        sort(arr.begin(), arr.end());

        t = arr[0];
        for(int i = 0; i < a; i++){
            if(arr[i] == t) arrA.push_back(arr[i]);
            else arrB.push_back(arr[i]);
        }

        cout << arrA.size() << " " << arrB.size() << "\n";

        for(auto it : arrA){
            cout << it << " ";
        }
        cout << "\n";
        for(auto it : arrB){
            cout << it << " ";
        }
        cout << '\n';
    }

}