#include<bits/stdc++.h>

using namespace std;

// Let the timer drop to 1 before using a tool.
// If a tool with value x is used at timer = 1:
//
// timer = min(1 + x, a)
// then the mandatory decrement happens immediately
//
// Effective extra seconds gained = min(1 + x, a) - 1
//                               = min(x, a - 1)
//
// Initial timer contributes b seconds on its own.

int main(){

    int t;
    cin >> t;

    while(t--){

        long long int a , b, n;
        cin >> a >> b >> n;
        long long int arr[n], sum = 0;
        for(long long int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] + 1 > a) arr[i] = a-1;
            sum += arr[i];
        }

        sum += b;

        cout << sum << "\n";
    }

}