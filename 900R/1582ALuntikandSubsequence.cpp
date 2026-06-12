#include<bits/stdc++.h>

using namespace std;

// need to find Number of sub sequence whose sum is s-1, w
// here s is the sum of original array
//
// It boils down to if the array contains 1s or not, if no 1, you can't obatin s-1 sub sequence
// also as 0 don't contribute to the sum, we can have a subsequence with & without zeros
// 
// finally in total : ones * 2^zeros
// why 2^zeros --> for multiple zeros in array, each zero is unqiue, or combination matter


int main(){
    int t;
    cin >> t;

    while(t--){
        long long n, ones = 0, zeros = 0;
        cin >> n;


        for(int i = 0; i < n; i++){
            int temp;
            cin >> temp;
            if(temp == 1) ones++;
            if(temp == 0) zeros++;
        }

        // cout << (long long)(pow(2,zeros) * ones) << "\n"; // this some time gives thee follwing error
        // wrong output format Expected integer, but "5.36871e+08" found
        // a better way to compute and store power of 2 is by bit shifting, left shifting bits, * by 2
        long long ans = ones;
        ans <<= zeros;
        cout << ans << '\n';

        // or a more compact way -> long long ans = ones * (1LL << zeros);
    }
}