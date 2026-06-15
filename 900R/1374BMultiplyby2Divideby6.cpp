#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a = 0, b = 0, k;

        while(n%2 == 0){
            n /= 2;
            a++;
        }

        while(n%3 == 0){
            n /= 3;
            b++;
        }

        k = n;

        if(k != 1 || a > b) cout << -1 << "\n";
        else cout << b - a + b << "\n";

    }
}

// Idea:
// We can represent the number as:
// n = 2^a * 3^b * k
//
// The operations affect only the powers of 2 and 3:
//
// Multiply by 2:
// 2^a * 3^b -> 2^(a+1) * 3^b
// (increases the count of factor 2)
//
// Divide by 6:
// 2^a * 3^b -> 2^(a-1) * 3^(b-1)
// (removes one factor of 2 and one factor of 3)
//
// Therefore, any other prime factors (k) can never be removed.
// If after removing all 2s and 3s, some number still remains,
// reaching 1 is impossible.
//
// Let d = a - b.
//
// Multiplying by 2 increases d, while dividing by 6 keeps d unchanged.
// So if a > b initially, we can never make the powers equal,
// meaning it is impossible to reach 1.
//
// If a <= b:
// 1. Multiply by 2 (b - a) times to make the powers equal.
//    We get 2^b * 3^b = 6^b
//
// 2. Divide by 6 exactly b times to remove all factors.
//
// Total moves = (b - a) + b = 2*b - a
//
// Implementation:
// Count how many times 2 divides n -> a
// Count how many times 3 divides the remaining n -> b
// If anything other than 1 remains, it is k (an extra prime factor).
// Apply the conditions above to get the answer.