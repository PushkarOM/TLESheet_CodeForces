#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[n];

    int minDiff = INT_MAX;

    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
        if(abs(arr[i]) < minDiff){
            minDiff = abs(arr[i]);
        }
    
    }

    cout << minDiff;
}