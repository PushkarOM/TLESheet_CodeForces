#include<bits/stdc++.h>

using namespace std;

// For numbers from 1 to n:
//
// The smallest possible sum using k distinct numbers is obtained
// by taking the first k numbers:
// minSum = 1 + 2 + ... + k
//
// The largest possible sum using k distinct numbers is obtained
// by taking the last k numbers:
// maxSum = (n-k+1) + (n-k+2) + ... + n
//
// Any sum between minSum and maxSum can also be formed using
// k distinct numbers.
//
// So there are no missing sums (no gaps) between minSum and maxSum.
//
// Therefore:
// if (x >= minSum && x <= maxSum) -> YES
// otherwise -> NO
// Below are just AP formulas for the sums
// long long int sumSmallest = (k*(k+1))/2, sumLargest = ((n*(n+1))/2) - ((n-k)*(n-k+1))/2;
        

int main(){

    int t;
    cin >> t;

    while(t--){

        long long int n, k, x, temp1, temp2;
        cin >> n >> k >> x;
        
        long long int sumSmallest = (k*(k+1))/2, sumLargest = ((n*(n+1))/2) - ((n-k)*(n-k+1))/2;
        



        if(x >= sumSmallest && x <= sumLargest){
            cout << "YES";
        }
        else{
            cout << "NO";
        }

        cout << "\n";


    }
}