#include<bits/stdc++.h>

using namespace std;


// A bus can have either 4 or 6 wheels.
// Feasibility:
// - Odd numbers of wheels are impossible because both bus types contribute even wheels.
// - The smallest possible valid wheel count is 4, so n < 4 is impossible.
//
// Minimum buses:
// - Use buses with the maximum wheels (6) as much as possible.
// - Therefore minimum buses = ceil(n / 6).
//
// Maximum buses:
// - Use buses with the minimum wheels (4) as much as possible.
// - Therefore maximum buses = floor(n / 4).
//
// Time Complexity: O(1) per test case.
// Space Complexity: O(1).

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        long long n;
        cin >> n;
        
        if(n < 4 || n % 2 != 0){
            cout << -1 << "\n";
            continue;
        }
        
        long long maxBus, minBus;
        
        maxBus = n/4;
        minBus = n%6 == 0 ? n/6 : (n/6) + 1;
        
        cout << minBus << " " << maxBus  << "\n";
        
    }
    
}